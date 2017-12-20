#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("maze1.in");
ofstream fout("maze1.out");

int row, col;
int a[300][100]; //保存栅栏 空格为0 其余障碍设成1
int f[300][100]; //保存最短步数
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int out[2][2];
int num = 0;

void dfs(int i, int j, int step)
{
    int new_i, new_j;
    f[i][j] = step;
    for(int index = 0; index < 4; ++index)
    {
        new_i = i + dir[index][0];
        new_j = j + dir[index][1];
        if(new_i>0 && new_j>0 && new_i<row && new_j<col && a[new_i][new_j]==0 && step+1<f[new_i][new_j])
            dfs(new_i, new_j, step + 1);
    }
}

int main()
{
    int W, H; fin >> W >> H;
    int res = 0;
    row = 2 * H + 1; col = 2 * W + 1;
    string str;
    getline(fin, str);
    for(int i = 0; i < row; ++i)
    {
        getline(fin, str);
        for(int j = 0; j < str.length(); ++j)
            if(str[j] != ' ')
                a[i][j] = 1;
    }

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            if((i==0 || j==0 || i==row-1 || j==col-1) && a[i][j] == 0)
            {
                out[num][0] = i; out[num++][1] = j;
            }
        }
    
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            f[i][j] = 1000000;
    
    dfs(out[0][0], out[0][1], 1);
    dfs(out[1][0], out[1][1], 1);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            if(f[i][j] != 1000000 && res < f[i][j]) res = f[i][j];
        }
     
    fout << res / 2 << endl;
    return 0;
}