#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int ma, mb, mc;
bool visit[25][25];
bool res[25];

void initial()
{
    for(int i = 0; i < 25; ++i)
    {
        for(int j = 0; j < 25; ++j)
            visit[i][j] = false;
        res[i] = false;
    }
}

void dfs(int a, int b)
{
    if(visit[a][b]) return;
    visit[a][b] = 1;
    int c = mc - a - b;
    if(a == 0) res[c] = true;

    //a->b
    if(a+b<=mb)
        dfs(0,a+b);
    else
        dfs(a-mb+b,mb);

    //a->c
    if(a+c<=mc)
        dfs(0,b);
    else
        dfs(a-mc+c,b);

    //b->a
    if(b+a<=ma)
        dfs(b+a,0);
    else
        dfs(ma,b-ma+a);

    //b->c
    if(b+c<=mc)
        dfs(a,0);
    else
        dfs(a,b-mc+c);

    //c->a
    if(c+a<=ma)
        dfs(c+a,b);
    else
        dfs(ma,b);

    //c->b
    if(c+b<=mb)
        dfs(a,c+b);
    else
        dfs(a,mb);;
}
int main()
{
    fin >> ma >> mb >> mc;
    initial();
    dfs(0, 0);
    int first = 0;
    for(int i = 0; i <= mc; ++i)
    {
        if(res[i])
        {
            if(first == 0)
            {
                fout << i;
                first = 1;
            }
            else
                fout << " " << i;
        }
    }
    fout << endl;
    return 0;
}