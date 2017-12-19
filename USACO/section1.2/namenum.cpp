#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream fin1("dict.txt");
ifstream fin("namenum.in");
ofstream fout("namenum.out");

string dict[5005];

string change(string name)
{
    string num = name;
    int i;
    for(i = 0; i < name.size(); ++i)
    {
        if(name[i] > 'Q')
            num[i] =  (name[i] - 1 - 'A') / 3 + 2 + '0';
        else
            num[i] = (name[i] - 'A') / 3 + 2 + '0';
    }
    return num;
}
int main()
{
    string val;
    string num, name;
    int flag = 0;
    fin >> val;
    while(fin1 >> name)
    {
        num = change(name);
        if(val == num)
        {
            fout << name << endl;
            flag = 1;
        }
    }
    if(flag == 0)
        fout << "NONE" << endl;
    return 0;
}