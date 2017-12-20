#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

long a[10];   
int overlap[10];
int flag[10];

int get_bit(long x)
{
    int bit = 0;
    while(x > 0)
    {
        a[bit++] = x % 10;
        overlap[x%10] += 1;
        x /= 10;
    }
    for(int i = 0; i < bit / 2; ++i)
    {
        long t = a[i];
        a[i] = a[bit - 1 - i];
        a[bit - 1- i] = t;
    }
    return bit;
}
bool check_round(long x)
{
    for(int i = 0; i < 10; ++i) { a[i] = 0; flag[i] = 0; overlap[i] = 0;}
    int bit = get_bit(x);
    for(int i = 0; i < 10; ++i)
    {
        if(overlap[0] > 0) return false;
        else if(overlap[i] > 1) return false;
    }
    flag[0] = 1;
    int cus = 0;
    int temp = bit;
    while(1) {
        --temp;
        cus = (a[cus] + cus) % bit;
        if(flag[cus]) return false;
        flag[cus] = 1;
        if(temp == 1) break;
    }
    if((a[cus] + cus) % bit == 0)
        return true;
    else 
        return false;
}
int main()
{
    long x; fin >> x;
    //cout << get_bit(x) << endl;
    //for(int i = 0; i < get_bit(x); ++i) cout << a[i] << ' ';
    for(long i = x + 1; ; ++i)
    {
        if(check_round(i))
        {
            fout << i << endl;
            break;
        }
    }
    return 0;
}