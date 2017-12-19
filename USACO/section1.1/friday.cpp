#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int counter[10];

bool judge(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
int compute_day(int year, int month)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    if(month == 2)
    {
        if(judge(year))
            return 29;
        else
            return 28;
    }
    return 30;
}
int main()
{
    int N; fin >> N;
    int year, day;
    int foward = 1;
    for(int i = 1; i <= 7; ++i)
        counter[i] = 0;
    for(int i = 0; i < N; ++i)
    {
        year = i + 1900;
        for(int j = 1; j <= 12; ++j)
        {
            
            if(i == 0 && j == 1)
            {
                day = 12;
            }
            else
            {
                if(j == 1)
                    day = compute_day(year, 12);
                else
                    day = compute_day(year, j - 1);
                
            }
            foward = (day + foward) % 7;
            counter[foward] += 1;
        }

    }
    fout << counter[6] << ' ';
    fout << counter[0];
    for(int i = 1; i <= 5; ++i)
    {
        fout << ' ' << counter[i];
    }
    fout << endl;
    return 0;
}
