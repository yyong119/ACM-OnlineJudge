#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

int N;
int ans1[3]; 
int ans2[3];
int tmp[3];
bool check(int i)
{
    int max_num, min_num;
    if(ans1[i] > ans2[i])
    {
        max_num = ans1[i];
        min_num = ans2[i];
    } else {
        max_num = ans2[i];
        min_num = ans1[i];
    }
    int temp1 = max_num - min_num;
    int temp2 = min_num + N - max_num;
    tmp[i] = (temp1 < temp2)?temp1:temp2;
    return tmp[i]<=4;
}

int no_overlap()
{
    if((check(0) && check(1) && check(2)))
        return (5-tmp[0])*(5-tmp[1])*(5-tmp[2]);
    else
        return 0;  
}
int main()
{
    fin >> N;
    for(int i = 0; i < 3; ++i) fin >> ans1[i];
    for(int i = 0; i < 3; ++i) fin >> ans2[i];
    if(N == 1) {
        fout << 1 << endl; return 0;
    } else if(N == 2) {
        fout << 8 << endl; return 0;    
    } else if(N == 3) {
        fout<<  27 << endl; return 0;
    } else if(N == 4) {
        fout << 128 - 4*4*4 << endl; return 0;
    }
    int res = no_overlap();
    fout << 250 - res << endl;
    return 0;
}