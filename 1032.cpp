#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
    int m, n;
	cin>>m>>n;
 
	int ack[4][20000];
	memset(ack,0,sizeof(ack));
	int i, j;
	for(j = 0; j < 20000; j++)
		ack[0][j]=j + 1;
	for(i = 1; i < 4; i++)
	{
		ack[i][0] = ack[i-1][1];
		for(j = 1; j < 20000; j++)
			ack[i][j] = ack[i-1][ack[i][j-1]];
	}
	cout<<ack[m][n]<<endl;
	return 0;
 
 
}