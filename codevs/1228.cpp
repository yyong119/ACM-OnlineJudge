#include<cstdio>
const int N=100000+10;

int n;
struct link{int y;link *next;}*head[N];
int L[N],R[N],dfstime,hash[N];
int sum[N*4],val[N*4];

void inlink(int x,int y)
{
	link *node=new link;
	node->y=y;
	node->next=head[x];
	head[x]=node;
}

void read()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		inlink(x,y);
		inlink(y,x);
	}
}

void dfs(int x)
{
	if(hash[x]) return;
	hash[x]=true;
	L[x]=++dfstime;
	for(link *node=head[x];node;node=node->next)
		dfs(node->y);
	R[x]=dfstime;
}

void downloading(int p,int l,int r,int m)
{
	if(val[p]!=-1)
	{
		sum[p<<1]=(m-l+1)*val[p];
		sum[(p<<1)+1]=(r-m)*val[p];
		val[p<<1]=val[(p<<1)+1]=val[p];
		val[p]=-1;
	}
}
void uploading(int p)
{
	if(val[p<<1]==val[(p<<1)+1] && val[p<<1]!=-1) val[p]=val[p<<1];
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
}

void modify(int p,int l,int r,int a,int b)
{
	if(a<=l && b>=r)
		if(val[p]!=-1)
		{
			val[p]=!val[p];
			sum[p]=(r-l+1)*val[p];
			return;
		}
	int m=(l+r)>>1;
	downloading(p,l,r,m);
	if(a<=m) modify(p<<1,l,m,a,b);
	if(b>m) modify((p<<1)+1,m+1,r,a,b);
	uploading(p);
}

int query(int p,int l,int r,int a,int b)
{
	if(a<=l && b>=r) return sum[p];
	int m=(l+r)>>1,x1=0,x2=0;
	downloading(p,l,r,m);
	if(a<=m) x1=query(p<<1,l,m,a,b);
	if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
	return x1+x2;
}

void work()
{
	dfs(1);
	modify(1,L[1],R[1],L[1],R[1]);
	int q;scanf("%d",&q);
	while(q--)
	{
		char op; int x;
		scanf("\n%c%d",&op,&x);
		if(op=='Q') printf("%d\n",query(1,L[1],R[1],L[x],R[x]));
		else modify(1,L[1],R[1],L[x],L[x]);
	}
}

int main()
{
	read();
	work();
	return 0;
}