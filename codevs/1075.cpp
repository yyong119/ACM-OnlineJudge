#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
bool a[1001];
int n,i,temp,total;
int main(){
	memset(a,false,sizeof(a));
	fscanf(stdin,"%d",&n);
	for(i=1; i<=n; i++){
		fscanf(stdin,"%d",&temp);
		if (!a[temp]){
			total+=1;
			a[temp]=true;
		}
	} 
	printf("%d\n",total);
	for (i=1; i<=1000; i++) if (a[i]) printf("%d%s",i," ");
	return 0;
}