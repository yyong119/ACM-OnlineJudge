#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

char a[250][15];
string str;

int main()
{
    int count = 0, Max = 0;
    while(fin >> a[count] && a[count++][0] != '.');
    str = "";
    string s;
    while(fin >> s) str += s;
    for(int i = 0; i < str.length(); ++i) {
        for(int j = 0; j < count; ++j) {
            if(i + strlen(a[j]) <= str.length()) {
                bool flag = true;
                for(int k = 0; k < strlen(a[j]); ++k) {
                    if(str[i+k] != a[j][k]) flag = false;
                }
                if(flag) 
                    if(Max < i + strlen(a[j]))
                    Max = i + strlen(a[j]);

            }
        }
        if(i + 1 > Max)
            break;
    }
    fout << Max << endl;
    return 0;
}