#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

int money[30];
long long f[26][10003];

int main()
{
    int V, N; fin >> V >> N;
    for(int i = 1; i <= V; ++i) fin >> money[i];
    f[0][0] = 1;
    for(int i = 1; i <= V; ++i)
    {
        for(int j = 0; j <= N; ++j)
        {
            if(f[i - 1][j] != 0)
            {
                int tmp = j;
                while(tmp <= N)
                {
                    f[i][tmp] += f[i-1][j];
                    tmp += money[i];
                }
            }
        }
    }
    fout << f[V][N] << endl;
    return 0;
}