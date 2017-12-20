#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char a[10][10];

int C_x, C_y, C_dir = 0;
int F_x, F_y, F_dir = 0;
int timee = 0;

int step(int i, int j, int dir, int *x, int *y)
{
    if(dir == 0) {
        if(i == 0) {
            dir = (dir + 1) % 4;
            *x = i, *y = j;
        }
        else if(a[i - 1][j] == '*') {
            dir = (dir + 1) % 4;
            *x = i, *y = j;
        }
        else {
            *x = i - 1; *y = j;
        }
    }
    else if(dir == 1) {
        if(j == 9) {
            dir = (dir + 1) % 4;
            *x = i; *y = j; 
        }
        else if(a[i][j + 1] == '*') {
            dir = (dir + 1) % 4;
            *x = i, *y = j;
        }
        else {
            *x = i; *y = j + 1;
        }
    }
    else if(dir == 2) {
        if(i == 9) {
            dir = (dir + 1) % 4;
            *x = i; *y = j; 
        }
        else if(a[i + 1][j] == '*') {
            dir = (dir + 1) % 4;
            *x = i, *y = j;
        }
        else {
            *x = i + 1; *y = j;
        }   
    }   
    else if(dir == 3) {
        if(j == 0) {
            dir = (dir + 1) % 4;
            *x = i; *y = j;
        }
        else if(a[i][j - 1] == '*') {
            dir = (dir + 1) % 4;
            *x = i, *y = j;
        }
        else {
            *x = i; *y = j - 1;
        }   
    }
    return dir;
}
int main()
{
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
        {
            fin >> a[i][j];
            if(a[i][j] == 'C') {
                C_x = i; C_y = j;
            }
            if(a[i][j] == 'F') {
                F_x = i; F_y = j;
            }
        }
    
    while(timee <= 10000)
    {
        int x1, y1;
        int x2, y2;

        C_dir = step(C_x, C_y, C_dir, &x1, &y1);
        F_dir = step(F_x, F_y, F_dir, &x2, &y2);

        ++timee;
        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        if(x1 == x2 && y1 == y2)
        {
            fout << timee << endl;
            return 0;
        }

        else
        {
            C_x = x1; C_y = y1;
            F_x = x2; F_y = y2;
        }
    }
    fout << 0 << endl;
    return 0;
}