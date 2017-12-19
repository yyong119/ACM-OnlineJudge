#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream fin("gift1.in");
ofstream fout("gift1.out");

int search(string a[], string b, int NP)
{
    for(int i = 0; i < NP; ++i)
    {
        if(a[i] == b)
            return i;
    }
    return -1;
}

int main()
{
    int NP, index;
    int num_all, num_per;
    string ch;
    string a[15];
    int m[15];
    string tmp[15];
    fin >> NP;
    //cin >> NP;
    for(int i = 0; i < NP; ++i)
    {
        fin >> a[i];
        m[i] = 0;
    }
    for(int i = 0; i < NP; ++i)
    {
        fin >> ch;
        fin >> num_all >> num_per;
        int master = search(a, ch, NP);
        m[master] -= num_all;
        if(num_per != 0)
        {
            int money = num_all / num_per;
            int remain = num_all - (num_all / num_per) * num_per;
            for(int j = 0; j < num_per; ++j)
            {
                fin >> tmp[j];
                index = search(a, tmp[j], NP);
                m[index] += money;
            }
            m[master] += remain;
        }
    }
    for(int i = 0; i < NP; ++i)
    {
        fout << a[i] << ' ' << m[i] << endl;
    }
    // insert code here...
    //cout << "Hello, World!\n";
    return 0;
}
