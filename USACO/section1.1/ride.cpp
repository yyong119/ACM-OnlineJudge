#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");


int main()
{
    char a[10], b[10];
    int res1 = 1, res2 = 1;
    int index1 = 0, index2 = 0;
    fin >> a >> b;
    while(a[index1] != '\0' && a[index1] != '\n' )
    {
        res1 *= a[index1] - 'A' + 1;
        ++index1;
    }
    while(b[index2] != '\0' && b[index2] != '\n' )
    {
        res2 *= b[index2] - 'A' + 1;
        ++index2;
    }
    if((res1 % 47) == (res2 % 47))
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}




















