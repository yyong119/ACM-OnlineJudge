#include<iostream>
#include<algorithm>
using namespace std;
struct data{
       int u,v,w;
       }e[5001];
int ft[501];
int gcd(int a,int b){return b? gcd(b,a%b):a;}
int find(int x){return x==ft[x]?x:ft[x]=find(ft[x]);}
bool inline cp(data a,data b){return a.w<b.w;}
int main()
{
    int i,x,u,v,mx,mn,r,start=0;
    int n,m,s,t,ansmx=1,ansmn=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
       cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e,e+m,cp);
    cin>>s>>t;
    while(start<m)
    {
         mn=mx=-1;
         for(i=1;i<=n;i++)ft[i]=i;
         for(x=start;x<m;x++)
         {
                u=find(e[x].u);v=find(e[x].v);ft[u]=v;
                if(find(s)==find(t)){mx=e[x].w;break;}
                 }
         if(mx==-1)
         {
                   if(!ansmn){cout<<"IMPOSSIBLE";return 0;}
                   else break;
         }
         for(i=1;i<=n;i++)ft[i]=i;
         for(;x>=0;x--)
         {
                 u=find(e[x].u);v=find(e[x].v);ft[u]=v;
                 if(find(s)==find(t)){mn=e[x].w;break;}
         }
         start=x+1;
         if(mn==-1)
         {
                   if(!ansmn){cout<<"IMPOSSIBLE";return 0;}
                   else break;
         }
         int r=gcd(mx,mn);mx/=r;mn/=r;
         if(ansmx*mn>ansmn*mx){ansmn=mn;ansmx=mx;}
              }
         if(ansmn==1)cout<<ansmx;
         else cout<<ansmx<<"/"<<ansmn<<endl;
    return 0;
}