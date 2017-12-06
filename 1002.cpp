#include <iostream>
int l,w,a,b,m,i,j;
int s[1001][1001];
int max(int p,int q){
	if (p>=q) return p; else return q;
}
int main(){
	using namespace std;
	cin>>l>>w;
	for (i=1; i<=l; i++)
		for (j=1; j<=w; j++){
			cin>>s[i][j];
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	cin>>a>>b;
	for (i=a; i<=l; i++)
		for (j=b; j<=w; j++)
		m=max(m,s[i][j]+s[i-a][j-b]-s[i][j-b]-s[i-a][j]);
	cout<<m;
	return 0;
}