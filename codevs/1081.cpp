#include <iostream>
#include <cstdio>
using namespace std;
long n,m,i,kind,a,b,temp,num;
long tree[400001][4];
void maketree(long l,long r,long p){
	long mid;
	if (l<r){
		mid=(l+r)/2;
		maketree(l,mid,2*p);
		maketree(mid+1,r,2*p+1);
	};
	tree[p][1]=l; tree[p][2]=r;
}
void insert(long l,long r,long num,long p){
	long mid;
	if ((tree[p][1]==l)&&(tree[p][2]==r)) {
		tree[p][0]+=num*(tree[p][2]-tree[p][1]+1);
		tree[p][3]+=num;
	}
	else{
		mid=(tree[p][1]+tree[p][2])/2;
		if (r<=mid) insert(l,r,num,2*p);
		else
		if (l>mid) insert(l,r,num,2*p+1);
		else{
			insert(l,mid,num,2*p);
			insert(mid+1,r,num,2*p+1);
		}
		tree[p][0]=tree[2*p][0]+tree[2*p+1][0];
	}
}
long count(long w,long p){
	long mid;
	if ((w==tree[p][1])&&(w==tree[p][2])) return tree[p][0];
	else{
		mid=(tree[p][1]+tree[p][2])/2;
		if (w<=mid) return tree[p][3]+count(w,2*p);
		else
		if (w>mid) return tree[p][3]+count(w,2*p+1);
	}
}
int main(){
	scanf("%ld",&n);
	maketree(1,n,1);
	for(i=1; i<=n; i++){
		scanf("%ld",&temp);
		insert(i,i,temp,1);
	}
	scanf("%ld",&m);
	for (i=1; i<=m; i++){
		scanf("%ld",&kind);
		if (kind==1){
			scanf("%ld%ld%ld",&a,&b,&num);
			insert(a,b,num,1);
		}	
		else{
			scanf("%ld",&a);
		 	printf("%ld\n",count(a,1));
		}
	}
	return 0;
}