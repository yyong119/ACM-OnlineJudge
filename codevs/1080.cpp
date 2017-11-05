#include <iostream>
#include <stdio.h>
using namespace std;
long n,m,i,kind,a,b,ans,temp;
long tree[400001][3];
void maketree(long l,long r,long p){
	long mid;
	if (l<r){
		mid=(l+r)/2;
		maketree(l,mid,2*p);
		maketree(mid+1,r,2*p+1);
	};
	tree[p][1]=l; tree[p][2]=r;
}
void insert(long num,long w,long p){
	long mid;
	if ((tree[p][1]==w)&&(tree[p][2]==w)) tree[p][0]+=num;
	else{
		mid=(tree[p][1]+tree[p][2])/2;
		tree[p][0]+=num;
		if (w<=mid) insert(num,w,2*p);
		else insert(num,w,2*p+1);
	}
}
void count(long l,long r,long p){
	long mid;
	if ((l==tree[p][1])&&(r==tree[p][2])) ans+=tree[p][0];
	else{
		mid=(tree[p][1]+tree[p][2])/2;
		if (r<=mid) count(l,r,2*p);
		else
		if (l>mid) count(l,r,2*p+1);
		else{
			count(l,mid,2*p);
			count(mid+1,r,2*p+1);
		}
	}
}
int main(){
	scanf("%ld",&n);
	maketree(1,n,1);
	for(i=1; i<=n; i++){
		scanf("%ld",&temp);
		insert(temp,i,1);
	}
	scanf("%ld",&m);
	for (i=1; i<=m; i++){
		scanf("%ld%ld%ld",&kind,&a,&b);
		if (kind==1) insert(b,a,1);		
		else
		{
			ans=0;
			count(a,b,1);
			printf("%ld\n",ans);
		}
	}
	return 0;
}