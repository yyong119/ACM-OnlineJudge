#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int f[250][150];

int main()
{
    int N, K;
    fin >> N >> K;
    for(int i = 1; i <= K; ++i)
    {
        f[1][i] = 1;
    }
    for(int i = 3; i <= N; i = i + 2) {
        for(int j = 2; j <= K; ++j) {
            for(int k = 1; k < i; ++k) 
                f[i][j] = (f[i][j] + f[k][j-1] * f[i-k-1][j-1]) % 9901;
        }
    }
    fout << (f[N][K] - f[N][K-1] + 9901) % 9901 << endl;
    return 0;
}