#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");

struct milk{
    int price; int amount;
};
milk a[50005];
void quick_sort(int low, int high)
{
    if(low >= high)
        return;
    int first = low;
    int last = high;
    milk key = a[first];
    while(first < last)
    {
        while(first < last && a[last].price >= key.price)
            --last;
        a[first] = a[last];
        while(first < last && a[first].price <= key.price)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    quick_sort(low, first - 1);
    quick_sort(first + 1, high);
}

int main()
{
    int N, M;
    fin >> N >> M;
    int res = 0; int index = 0;
    for(int i = 0; i < M; ++i)
    {
        fin >> a[i].price >> a[i].amount ;
    }
    quick_sort(0, M - 1);
    //for(int i = 0; i < M; ++i)
    //{
    //    cout << a[i].price << " " << a[i].amount << endl;;
    //}
    while(1)
    {
        if(N > a[index].amount)
        {
            res += a[index].price * a[index].amount;
            //cout << a[index].price << " " << a[index].amount << endl;
            N -= a[index].amount;
            ++index;
        }
        else
        {
            res += a[index].price * N;
            break;
        }
    }
    fout << res << endl;
    return 0;
}