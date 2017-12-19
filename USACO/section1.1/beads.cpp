#include <iostream>
#include <fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

char str[2000];

void input(int x)
{
    for(int i = 0; i < x; ++i)
    {
        fin >> str[i];
        str[i + x] = str[i];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x, res = 0;
    fin >> x;
    input(x);
    for(int i = 0; i < x; ++i)
    {
        int n = 0, m = 0;
        char s = ' ';
        int j = i;
        for(j = i; j < i + x; ++j)
        {
            if(str[j] == 'w')
                ++n;
            else
                break;
        }
        s = str[j];
        for(j = i + n; j < i + x; ++j)
        {
            if(str[j] == s || str[j] == 'w')
                ++n;
            else
                break;
        }
        j = i + x - 1;
        for(;j >= i; --j)
        {
            if(str[j] =='w')
                ++m;
            else
                break;
        }
        s = str[j];
        for(j = i + x -1 - m; j >= i; --j)
        {
            if(str[j] == s || str[j] == 'w')
                ++m;
            else break;
        }
        if(n + m > res)
            res = n + m;
        if(res >= x)
        {
            res = x;
            break;
        }
    }
    fout << res << endl;
    //cout << "Hello, World!\n";
    return 0;
}
