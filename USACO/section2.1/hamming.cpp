#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

int N, B, D;
int a[100];
int size;

int ham_dis(int x, int y)
{
    int res = x ^ y;
    int tmp = 0;
    for(int i = 1; i <= B; ++i)
    {
        if((res & 1) == 1) {
            ++tmp;
        }
        res >>= 1;
    }
    return tmp;
    
}   

bool judge(int x)
{
    for(int i = 0; i <= size; ++i)
    {
        if(ham_dis(x, a[i]) < D) return false;
    }
    return true;
}
int main()
{
    fin >> N >> B >> D;
    for(int i = 1; i < 256 && size < N - 1; ++i)
    {
        if(judge(i))
            a[++size] = i;
    }
    for(int i = 0; i < N / 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
            fout << a[i * 10+j] << " ";
        fout << a[i * 10 + 9] << endl;
    }
    if(N % 10 != 0)
    {
    for(int i = 0; i < N % 10 - 1; ++i)
    {
        fout << a[10 * (N / 10) + i] << " ";
    }
    //cin >> N >> B >> D;
    fout << a[N - 1] << endl;
    }
    return 0;
}