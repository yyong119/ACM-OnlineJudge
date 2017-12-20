#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

int V;
int a[35];
int tmp[35];
int G; 
int b[16][35];
int res[16];
int size = 0;
int ans[35][35];

bool judge(int x)
{
    size = 0;
    for(int i = 0; i < G; ++i){
        res[i] = 0;
    }
    for(int i = 0; i < V; ++i)
    {
        tmp[i] = 0;
    }
    for(int i = 0; i < G; ++i)
    {
        if((x & 1) == 1) {
            res[i] = 1;
            ++size;
        for(int j = 0; j < V; ++j) {
            tmp[j] += b[i][j];
        }
        }
        x >>= 1;
    }
    for(int i = 0; i < V; ++i)
        if(tmp[i] < a[i]) return false;
    return true;
}
int main()
{
    int index = 0;
    int min_count = 30;
    int fina = 0;
    fin >> V;
    for(int i = 0; i < V; ++i) fin >> a[i];
    fin >> G;
    for(int i = 0; i < G; ++i) for(int j = 0; j < V; ++j) fin >> b[i][j];
    for(int i = 1; i < (1 << G); ++i)
    {
        if(judge(i)) 
        {
            if(size < min_count) 
            {
            for(int i = 0; i < G; ++i)
            {
                ans[size][i] = res[i];
            }
            min_count = size;
            }
        }
    }
    fout << min_count << " ";
    for(int i = 0; i < G; ++i)
    {
        if(ans[min_count][i])
        {
            if(++fina == min_count)
             fout << i + 1 << endl; 
            else
                fout << i + 1 << " ";
        }
    }
    return 0;
}