#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("castle.in");
ofstream fout("castle.out");


int a[52][52];
int south[52][52];
int north[52][52];
int east[52][52];
int west[52][52];
int room_num = 1; //记录房间的个数
int room[2800]; //记录房间的大小
int mark[52][52];
int M, N;
int max_room=0;
int wall_row, wall_col;
char dir;

void input()
{   
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j) {
            fin >> a[i][j];
            if(a[i][j] >= 8) {south[i][j] = 1; a[i][j] -= 8;}
            if(a[i][j] >= 4) {east[i][j] = 1; a[i][j] -= 4;}
            if(a[i][j] >= 2) {north[i][j] = 1; a[i][j] -= 2;}
            if(a[i][j] >= 1) {west[i][j] = 1; a[i][j] -= 1;}
        }       
}


void dfs(int i, int j)
{
    if(mark[i][j] != 0) return;
    mark[i][j] = room_num;
    room[room_num] += 1;
    if(north[i][j] == 0 && i > 1)
        dfs(i - 1, j);
    if(south[i][j] == 0 && i < N)
        dfs(i + 1, j);
    if(east[i][j] == 0 && j < M)
        dfs(i, j + 1);
    if(west[i][j] == 0 && j > 1)
        dfs(i, j - 1);
    
}

void find_room()
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
        {
            if(mark[i][j] == 0)
            {
                dfs(i, j); /*cout << i << " " << j << endl;*/++room_num;
            }
        }
}

int findmax()  //没砸墙前的最大房间的大小
{
    int m = room[1];
    for(int i = 1;i<room_num;++i) if(room[i] > m) m = room[i];
    return m;
}

void break_wall()
{
    for(int j = 1; j <= M; ++j)
        for(int i = N; i >= 1; --i)
        {
            if(north[i][j] == 1 && i > 1 && mark[i][j] != mark[i - 1][j])
            {
                int temp = room[mark[i][j]] + room[mark[i -1][j]];
                if(max_room < temp)
                {
                    max_room = temp;
                    wall_row = i; wall_col = j; dir = 'N';
                }
            }

            if(east[i][j] == 1 && j < M && mark[i][j] != mark[i][j + 1])
            {
                int temp = room[mark[i][j]] + room[mark[i][j + 1]];
                if(max_room <temp)
                {
                    max_room = temp;
                    wall_row = i; wall_col = j; dir = 'E';
                }
            }
        }
}

int main()
{
    fin >> M >> N;
    input();
    find_room();
    break_wall();
    fout << room_num-1<< '\n' << findmax() << '\n' << max_room << '\n' << wall_row << ' ' << wall_col << ' ' << dir << '\n';
    return 0;
}