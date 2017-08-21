#include <iostream>
int l,i,j,rest,x,y,head,tail,times;
int map[101][101],dir[5][3],line[200][10001][3];
int main(){
	using namespace std;
	dir[1][2]=1; dir[2][2]=-1; dir[3][1]=1; dir[4][1]=-1;
	cin>>l; rest=l*l;
	for (i=1; i<=l; i++)
		for (j=1; j<=l; j++){
			cin>>map[i][j];
			if (map[i][j]) rest--;
			if (map[i][j]==1){
				tail++;
				line[times][tail][1]=i; line[times][tail][2]=j;
			}
		}
	line[times][0][0]=tail;
	while (rest){
		times++; tail=0;
		for (head=1; head<=line[times-1][0][0]; head++)
		for (i=1; i<=4; i++){
			x=line[times-1][head][1]+dir[i][1]; 
			y=line[times-1][head][2]+dir[i][2];
			if ((map[x][y]==0)&&(x>=1)&&(x<=l)&&(y>=1)&&(y<=l)){
				tail++; line[times][tail][1]=x; line[times][tail][2]=y;
				map[x][y]=1; rest--;
			}
		}
		line[times][0][0]=tail;
	}
	cout<<times;
	return 0;
}