#include <iostream>
 
using namespace std;
int data[4][4]={0},mina=1000,answer[1000],way[1000],number[10]={0};
void work(int ii)
{
    if (ii==1)
    {
        data[1][1]=(data[1][1]+3)%12;
        data[1][2]=(data[1][2]+3)%12;
        data[2][1]=(data[2][1]+3)%12;
        data[2][2]=(data[2][2]+3)%12;
    }
    else if (ii==2)
    {
        data[1][1]=(data[1][1]+3)%12;
        data[1][2]=(data[1][2]+3)%12;
        data[1][3]=(data[1][3]+3)%12;
    }
    else if (ii==3)
    {
        data[1][2]=(data[1][2]+3)%12;
        data[1][3]=(data[1][3]+3)%12;
        data[2][2]=(data[2][2]+3)%12;
        data[2][3]=(data[2][3]+3)%12;
    }
    else if (ii==4)
    {
        data[1][1]=(data[1][1]+3)%12;
        data[2][1]=(data[2][1]+3)%12;
        data[3][1]=(data[3][1]+3)%12;
    }
    else if (ii==5)
    {
        data[1][2]=(data[1][2]+3)%12;
        data[2][1]=(data[2][1]+3)%12;
        data[2][2]=(data[2][2]+3)%12;
        data[2][3]=(data[2][3]+3)%12;
        data[3][2]=(data[3][2]+3)%12;
    }
    else if (ii==6)
    {
        data[1][3]=(data[1][3]+3)%12;
        data[2][3]=(data[2][3]+3)%12;
        data[3][3]=(data[3][3]+3)%12;
    }
    else if (ii==7)
    {
        data[2][1]=(data[2][1]+3)%12;
        data[2][2]=(data[2][2]+3)%12;
        data[3][1]=(data[3][1]+3)%12;
        data[3][2]=(data[3][2]+3)%12;
    }
    else if (ii==8)
    {
        data[3][1]=(data[3][1]+3)%12;
        data[3][2]=(data[3][2]+3)%12;
        data[3][3]=(data[3][3]+3)%12;
    }
    else if (ii==9)
    {
        data[2][2]=(data[2][2]+3)%12;
        data[2][3]=(data[2][3]+3)%12;
        data[3][2]=(data[3][2]+3)%12;
        data[3][3]=(data[3][3]+3)%12;
    }
}
void dfssearch(int jj)
{
    int iii,jjj;
    bool ok=true;
    for (iii=1;iii<=3;iii++) for (jjj=1;jjj<=3;jjj++) if (data[iii][jjj]!=0) ok=false;
    if (ok && jj-1<mina)
    {
        mina=jj-1;
        for (iii=1;iii<=mina;iii++) answer[iii]=way[iii];
    }
    else if (!ok && jj-1<mina)
    {
        for (iii=way[jj-1];iii<=9;iii++)
        {
            if (number[iii]==3) continue;
            work(iii);
            number[iii]++;
            way[jj]=iii;
            dfssearch(jj+1);
            work(iii);
            work(iii);
            work(iii);
            number[iii]--;
        }
    }
}
int main()
{
 
    int i,j;
    for (i=1;i<=3;i++)
    for (j=1;j<=3;j++)
    {
        cin >> data[i][j];
        if (data[i][j]==12) data[i][j]=0;
    }
    way[0]=1;
    dfssearch(1);
    for (i=1;i<=mina-1;i++) cout << answer[i] << ' ';
    cout << answer[mina];
    return 0;
}