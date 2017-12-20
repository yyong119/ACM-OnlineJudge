#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");

int a[105][105];
int f[105][105];
int num = 0;

int max(int a, int b)
{
    return (a > b) ? a:b;
}
void dfs(int i, int j)
{   
    if(f[i][j]) return;
    //f[i][j] += a[i][j];
    f[i][j] = 1;
    for(int m = 1; m <= num; ++m)
    {
        if(i != m)
        {   
            a[i][m] += a[j][m];
            if(a[i][m] > 50 && !f[i][m])
                dfs(i, m);
        }   
    }
    //}
}
int main()
{
    int i, j, p, N; fin >> N;
    for(int m = 0; m < N; ++m)
    {
        fin >> i >> j >> p;
        a[i][j] = p;
        num = max(num, max(i, j));
    }
    for(int m = 1; m <= num; ++m)
    {
        for(int n = 1; n <= num; ++n)
        {
            if(m != n && a[m][n] > 50)
                dfs(m, n);
        }
    }
    //for(int m = 1; m <= num; ++m)
    //    for(int n = 1; n <= num; ++n)
    //        cout << m << " " << n << " " << f[m][n] << endl;
    for(int m = 1; m <= num; ++m)
    {
        for(int n = 1; n <= num; ++n)
        {
            if(f[m][n])
                fout << m <<" " <<  n << endl;
        }
    }
    return 0;
}