#include<stdio.h>  
#include<stdlib.h>  
#include<queue>  
#include<map>  
using namespace std;  
const int dx[]={1, -1, 0, 0}; 
const int dy[]={0, 0, 1, -1};  
struct status 
{                                      
    int hash, step, last;  
    int map[6][6];  
}first;  
queue<struct status> Q;  
map<int, bool> h[3];
int gethash(status a) 
{  
    int res = 0;  
    int k = 1;  
    int i, j;  
    for (i = 1; i <= 4; i++)  
        for (j = 1; j <= 4; j++)  
        {  
            res += a.map[i][j] * k;  
            k *= 3;  
        }  
    return res;  
}  
bool check(status a) 
{  
    int i, j;  
    for (i = 1; i <= 4; i++)
    {  
        bool flag = true;  
        for (j = 2; j <= 4; j++)  
            if(a.map[i][j-1] != a.map[i][j])  
                flag = false;  
        if (flag)   
            return true;  
    }  
    for (i = 1;i <= 4; i++)
    {  
        bool flag = true;  
        for (j = 2; j <= 4; j++)  
            if(a.map[j][i] != a.map[j-1][i])  
        flag = false;  
        if (flag)   
            return true;  
    }  
    if (a.map[1][1] == a.map[2][2]) 
        if (a.map[2][2] == a.map[3][3])  
            if (a.map[3][3] == a.map[4][4])  
                return true;  
    if (a.map[1][4] == a.map[2][3])  
        if (a.map[2][3] == a.map[3][2])  
            if (a.map[3][2] == a.map[4][1])  
                return true;  
    return false;  
}  
void move(status now, int x, int y, int k) 
{  
    status tmp = now;  
    int tmpx = x + dx[k];      
    int tmpy = y + dy[k];  
    if (tmpx < 1 || tmpx > 4) return ;   
        if (tmpy < 1 || tmpy > 4) return ;  
            if (tmp.map[tmpx][tmpy] == tmp.last) 
                return ;   
    tmp.last = 3 - tmp.last; 
    swap(tmp.map[tmpx][tmpy], tmp.map[x][y]);   
    tmp.hash = gethash(tmp);  
    tmp.step++;                           
    if (check(tmp))                    
    {  
        printf("%d", tmp.step);  
        exit(0);  
    }  
    if (!h[tmp.last][tmp.hash])   
    {   
        h[tmp.last][tmp.hash] = 1;  
        Q.push(tmp);  
    }   
}  
void bfs()  
{  
    first.hash = gethash(first); 
    first.last = 1;     
    Q.push(first);  
    first.last = 2;  
    Q.push(first);  
    while (!Q.empty())  
    {  
        status now;  
        now = Q.front();  
        Q.pop();  
        int x1 = -1, x2 = -1, y1 = -1, y2 = -1;  
        int i, j, k;  
        for (i = 1; i <= 4; i++)  
            for (j = 1; j <= 4; j++) 
                if (!now.map[i][j])  
                {  
                    if (x1 == -1 && y1 == -1)  
                    {  
                        x1 = i;          
                        y1 = j;  
                    }  
                    else  
                    {  
                        x2 = i;  
                        y2 = j;  
                    }  
                }  
        for (k = 0; k < 4; k++) 
        {  
            move(now, x1, y1, k);  
            move(now, x2, y2, k);  
        }  
    }  
}  
int main()  
{  
    int i, j;  
    for (i = 1; i <= 4; i++)  
    {  
        char s[10];  
        scanf("%s", s);  
        for (j = 0; j < 4; j++) 
        {                        
            if (s[j] == 'B') first.map[i][j+1] = 1;  
            if (s[j] == 'W') first.map[i][j+1] = 2;  
        }  
    }  
    bfs();  
    return 0;  
} 