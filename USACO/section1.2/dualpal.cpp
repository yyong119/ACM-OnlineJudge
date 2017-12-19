#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

int a[15][100000];
int str[15];

int change(int num, int jinzhi)
{
    int i = 0;
    while(num > 0)
    {
        a[jinzhi][i++] = num % jinzhi;
        num /= jinzhi;
    }
    return i;
}

bool check()
{
    int flag1 = 0, flag2 = 0;
    for(int jinzhi = 2; jinzhi <= 10; ++jinzhi)
    {
        flag2 = 0;
        for(int j = 0; j < str[jinzhi] / 2; ++j)
        {
            if(a[jinzhi][j] != a[jinzhi][str[jinzhi] - 1 - j])
            {
                flag2 = 1;
                break;
            }
        }
        if(!flag2) ++flag1;
    }
    if(flag1 >= 2) return true;
    return false;
}

int main()
{
    int N, S;
    fin >> N >> S;
    int flag = 0;

    for(int i = S + 1; ;++i)
    {
        for(int j = 2; j <= 10; ++j)
        {
            str[j] = change(i, j);
        }

        if(check())
        {
            if(flag == N)
                return 0;
            else
            {
                fout << i << endl;
                ++flag;
            }
        } 
    }
    return 0;
}