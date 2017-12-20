#include<iostream>
#include<fstream>
using namespace std;

#define oo 1047400000
ifstream fin("comehome.in");
ofstream fout("comehome.out");

int P;
int a[55][55], f[55];
int cha(char x)
{
    if(x >= 'a' && x <= 'z')
        return x - 'a';
    else if(x >= 'A' && x <= 'Z')
    {
        
        f[x - 'A' + 26] = 1;
        return x - 'A' + 26;
    }
}

void floyd()
{
    for(int k = 0; k < 52; ++k)
        for(int i = 0; i < 52; ++i)
            for(int j = 0; j < 52; ++j)
            {
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
}
int main()
{
    fin >> P;
    int res = oo;
    char ch;
    for(int i = 0; i < 52; ++i)
        for(int j = 0; j < 52; ++j)
        {
            if(i != j) 
                a[i][j] = oo;
        }
    for(int i = 0; i < P; ++i)
    {
        char c1, c2;
        int dis;
        int x, y;
        fin >> c1 >> c2 >> dis;
        x = cha(c1); y = cha(c2);
        //这两地方 导致此题很久没过
        if(a[x][y] > dis) //这也很重要可能重复输入
        {
            //不要忘记写两遍！！！这和邻接表的输入有区别
            a[x][y] = dis;
            a[y][x] = dis;
        }
    }
    floyd();

    for(int i = 26; i < 51; ++i)
    {
        if(f[i] && a[i][51] < res)
        {
            res = a[i][51];
            ch = (char)(i + 'A' - 26);
        }
    }    
    fout << ch << " " << res << endl;
    return 0;
}