#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int a[150000];
int square[150000];
struct A{
    int start;
    int diff;
} x[150000];

int N, M;
int sum_square = -1;

void initial()
{
    for(int i = 0; i <= M; ++i)
    {
        for(int j = 0; j <= M; ++j)
        {
            a[i * i + j * j] = 1;
        }
    }
    for(int i = 0; i <= M * M * 2; ++i)
    {
        if(a[i]) square[++sum_square] = i;
    }
}

int my_cmp(const A &x1, const A &x2)
{
    if(x1.diff < x2.diff)
        return 1;
    if(x1.start < x2.start)
        return 1;
    return 0;
}
int main()
{
    fin >> N >> M;
    int res_len = -1;
    initial();
    for(int i = 0; i <= sum_square; ++i)
    {
        for(int j = i + 1; j <= sum_square; ++j)
        {
            int di = square[j] - square[i];
            if((square[i] + (N - 1) * di) > square[sum_square]) //如果太大此时就可以排除了
                break;
            int k;
            for(k = 2; k < N; ++k)
            {
                if(a[square[i] + k * di] == 0)
                    break;
            }
            if(k == N)
            {
                x[++res_len].start = square[i];
                x[res_len].diff = di;
            }
        }
    }
    sort(x, x + res_len + 1, my_cmp);
    for(int i = 0; i <= res_len; ++i)
        fout << x[i].start << " " << x[i].diff << endl;
    if(res_len == -1)
        fout << "NONE" << endl;
    return 0;
}
