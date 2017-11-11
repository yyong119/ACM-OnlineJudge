#include<stdio.h>  
#include<iostream>  
using namespace std;  
const int MAX_N = 51;  
const int MAX_M = 1001;  
int R, C, N;  
int x, y;  
int turn[MAX_M]; 
int M[MAX_N][MAX_N]; 
char A[MAX_N][MAX_N];
int vis[MAX_N][MAX_N][MAX_M];
void DFS(int x, int y, int t)  
{  
    if (vis[x][y][t]) return;
    vis[x][y][t] = 1; 
    if (t > N) 
    {  
        A[x][y] = '*';  
        return;  
    }  
    if (turn[t] == 1)  
    {  
        x--;             
        while (x >= 1 && M[x][y])  
        {  
            DFS(x, y, t + 1);   
            x--;  
        }  
    }  
    if (turn[t] == 2)           
    {  
        x++;  
        while (x <= R && M[x][y])  
        {  
            DFS(x, y, t+1);  
            x++;  
        }  
    }  
    if (turn[t] == 3)             
    {  
        y--;  
        while (y >= 1 && M[x][y])  
        {  
            DFS(x, y, t + 1);  
            y--;   
        }   
    }                  
    if (turn[t] == 4)            
    {  
        y++;  
        while (y <= C && M[x][y])  
        {  
            DFS(x, y, t + 1);  
            y++;  
        }  
    }  
}  
int main()  
{  
    int i, j;  
    cin>>R>>C;  
    for (i = 1; i <= R; i++)  
    {  
        for (j = 1; j <= C; j++)  
        {  
            cin>>A[i][j];  
            if (A[i][j] == '.') M[i][j] = 1;  
            if (A[i][j] == 'X') M[i][j] = 0;  
            if (A[i][j] == '*')   
            {  
                A[i][j] = '.';  
                M[i][j] = 1;  
                x = i;  
                y = j;  
            }  
        }  
    }  
    cin>>N;  
    for (i = 1; i <= N; i++)  
    {  
        char dir[5];  
        cin>>dir;  
        if (dir[0] == 'N') turn[i] = 1;                
        if (dir[0] == 'S') turn[i] = 2;  
        if (dir[0] == 'W') turn[i] = 3;  
        if (dir[0] == 'E') turn[i] = 4;  
    }  
    DFS(x, y, 1);  
    for (i = 1; i <= R; i++)  
    {  
        for (j = 1; j <= C; j++)  
            printf("%c", A[i][j]);  
        if(i != R)   
            printf("\n");  
    }  
    return 0;  
}  