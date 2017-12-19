#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

int a[10];
int N;

void quick_sort(int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last)
    {
        while(first < last && a[last] >= key)
            --last;
        a[first] = a[last];
        while(first < last && a[first] <= key)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    quick_sort(low, first - 1);
    quick_sort(first + 1, high);
}

bool check(int num)
{
    int flag = 0;
    while(num > 0)
    {
        int x = num % 10;
        flag = 0;
        for(int i = 0; i < N; ++i)
        {
            if(x == a[i]) flag = 1;
        }
        if(flag == 0) return false;
        num = num / 10;
    }
    return true;
}

int main()
{
    fin >> N;
    int res = 0;
    for(int i = 0; i < N; ++i) fin >> a[i];
    quick_sort(0, N - 1);
    for(int i1 = 0; i1 < N; ++i1)
    {
        for(int i2 = 0; i2 < N; ++i2)
        {
            for(int i3 = 0; i3 < N; ++i3)
            {
                for(int i4 = 0; i4 < N; ++i4)
                {
                    for(int i5 = 0; i5 < N; ++i5)
                    {
                        int num1 = 100 * a[i1] + 10 * a[i2] + a[i3];
                        int sum1 = num1 * a[i5];
                        int sum2 = num1 * a[i4];
                        if((sum1 < 1000) && (sum2 < 1000) && (sum2 * 10 + sum1 < 10000))
                        {
                            if(check(sum1) && check(sum2) && check(sum2 * 10 + sum1))
                                ++res;
                        }
                    }
                }
            }
        }
    }
    fout << res << endl;

    return 0;
}