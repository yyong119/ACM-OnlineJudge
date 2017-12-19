#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

int a[1005];
int N;

void quick_sort(int low, int high)
{
    if(low >= high)
        return;
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

long long cal(int num)
{
    long long res = 0;
    for(int i = 0; i < N; ++i)
    {
        if((a[i] >= num) && (a[i] <= num + 17))
            continue;
        else if(a[i] < num)
            res += (a[i] - num) * (a[i] - num);
        else if(a[i] > num + 17)
            res += (a[i] - num - 17) * (a[i] - num - 17);
    }
    return res;
}
int main()
{   
    fin >> N;
    long long  min_num = 214740000000000;
    long long  res;
    for(int i = 0; i < N; ++i) fin >> a[i];
    quick_sort(0, N - 1);
    for(int i = a[0]; i <= a[N - 1]; ++i)
    {
        res = cal(i);
        if(res < min_num) min_num = res;
    }
    fout << min_num << endl;
    //cout << "helo" << endl;
    return 0;
}