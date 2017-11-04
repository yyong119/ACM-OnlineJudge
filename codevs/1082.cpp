#include <cstdio>
#include <cstdlib>
#include <cstring>
#define rep(a,b) for (int i=a;i<=b;i++)
#define lowbit(x)(((~x)+1)&x)
#define MAXN 200010
long long t0[MAXN],t1[MAXN],t[MAXN],n,m;
long long getsum(int l,int r){return t[r]-t[l-1];}
long long getsum0(int x){
	long long rec=0,i=x;
	while (i) rec+=t0[i],i-=lowbit(i);
	return rec;
}
long long getsum1(int x){
	long long rec=0,i=x;
	while (i) rec+=t1[i],i-=lowbit(i);
	return rec;
}
void Add0(int x,int y){while(x<=n)t0[x]+=y,x+=lowbit(x);}
void Add1(int x,int y){while(x<=n)t1[x]+=y,x+=lowbit(x);}
int main(){
	memset(t0,0,sizeof(t0));
	memset(t1,0,sizeof(t1));
	memset(t,0,sizeof(t));
	scanf("%d",&n);
	int x;
	rep(1,n) scanf("%d",&x),t[i]=t[i-1]+x;
	scanf("%d",&m);
	while (m--){
		int l,r,k;
		scanf("%d%d%d",&x,&l,&r);
		if (x==1){
			scanf("%d",&k);
			Add0(l,k),Add0(r+1,-k);
			Add1(l,(l-1)*k),Add1(r+1,-r*k);
		} else 
        printf("%lld\n",getsum(l,r)+(1-l)*getsum0(l)+r*getsum0(r)-(getsum1(r)-getsum1(l)));
	}
	return 0;
}