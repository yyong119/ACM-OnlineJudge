#include<stdio.h>
#define MAX_N 100000000
char h[MAX_N>>2|1];
int main() {
	int n ,m ;
	scanf("%d%d",&n,&m);
	for(int i=0,temp;i!=n;++i) {
		scanf("%d",&temp);
		temp +=MAX_N;
		h[temp/8]|=(1<<temp%8);
	}
	for(int i=0,temp;i!=m;++i) {
		scanf("%d",&temp);
		temp +=MAX_N;
		printf("%s\n",h[temp/8]&(1<<temp%8) ? "YES" : "NO");
	}
	return 0;
}