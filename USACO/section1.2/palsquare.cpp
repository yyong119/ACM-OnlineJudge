#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

int B;
int a[1000000], b[1000000];
int changeToStringA(int num)
{
    int i = 0;
    while(num > 0)
    {
        a[i++] = num % B;
        num = num / B;
    }
    return i;
}
int changeToStringB(int num)
{
    int i = 0;
    while(num > 0)
    {
        b[i++] = num % B;
        num /= B;
    }
    return i;
}
bool check(int i)
{
    for(int j = 0; j < i /2; ++j)
    {
        if(b[j] != b[i - 1 - j])
            return false;
    }
    return true;
}

int main()
{
    fin >> B;
    for(int i = 1; i <= 300; ++i)
    {
        int num = i * i;
        int length = changeToStringB(num);
        if(check(length))
        {
            int l2 = changeToStringA(i);
            for(int j = l2 - 1; j >= 0; --j)
            {
                if(a[j] >= 10)
                {
                    fout << (char)(a[j] + 'A' - 10);
                }
                else
                    fout << a[j];
            }
            fout << " "; 
            for(int j = 0; j < length; ++j)
            {
                if(b[j] >= 10)
                    fout << (char)(b[j] + 'A' - 10);
                else
                    fout <<  b[j];
            }
            fout << endl;
        }
    }
    return 0;
}