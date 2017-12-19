#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[20][20], b[20][20], temp[20][20], other[20][20];
int N;

ifstream fin("transform.in");
ofstream fout("transform.out");
bool com1()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(temp[i][j] != b[i][j])
                return false;
    return true;
}
bool com2()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(other[i][j] != b[i][j])
                return false;
    return true;
}
void way_1()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            temp[j][N-1-i] = a[i][j];
}
void way_2()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            temp[N - 1 - i][N - 1 - j] = a[i][j];
}
void way_3()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            temp[N-1-j][i] = a[i][j];
}
void way_4()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            temp[i][N-1-j] = a[i][j];
}
void back()
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            temp[i][j]= a[i][j];
}
int main()
{
    fin >> N;
    for(int i = 0;i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            fin >> a[i][j];
            temp[i][j] = a[i][j];
        }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            fin >> b[i][j];
    for(int i = 1; i <= 7; ++i)
    {
        //cout << "hello" << endl;
        if(i == 1)
        {
            way_1();
            if(com1())
            {
                fout << "1" << endl;
                return 0;
            }
        }
        if(i == 2)
        {
            //back();
            way_2();
            if(com1())
            {
                fout << "2" << endl;
                return 0;
            }
        }
        if(i == 3)
        {
            //back();
            way_3();
            if(com1())
            {
                fout << "3" << endl;
                return 0;
            }
        }
        if(i == 4)
        {
            //back();
            way_4();
            if(com1())
            {
                fout << "4" << endl;
                return 0;
            }
        }
        if(i == 5)
        {
            //fout << "hello" << endl;
            //back();
            way_4();
            //way_1();
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    other[j][N-1-i] = temp[i][j];
            if(com2())
            {
                fout << "5" << endl;
                return 0;
            }
            
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    other[N - 1 - i][N - 1 - j] = temp[i][j];
            if(com2())
            {
                fout << "5" << endl;
                return 0;
            }
            
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    other[N-1-j][i] = temp[i][j];
            if(com2())
            {
                fout << "5" << endl;
                return 0;
            }
        }
        if(i == 6)
        {
            back();
            
            if(com1())
            {
                fout << "6" << endl;
                return 0;
            }
        }
        if(i == 7)
        {
            fout << "7" << endl;
            return 0;
        }
    }
    return 0;
}