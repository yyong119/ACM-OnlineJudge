#include<cstdio>
 
#include<cstring>
 
char B[1<<15],*S=B,*T=B,ch;
 
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
 
int aa;int F(){
 
    while(ch=getc(),ch<'0'||ch>'9');aa=ch-'0';
 
    while(ch=getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return aa;
 
}
 
#define N 100010
 
int n,m,p,x,y,i,vis[N],op,tim,cnt[N],nxt[N],cir[N],maxl,ans;
 
int t[1<<18][60],tag[1<<18],add[1<<18],tmp[60],mod[N];
 
void mt(int o){
 
    t[o][0]=t[o<<1][0]+t[o<<1|1][0];
 
    if(tag[o]=tag[o<<1]&tag[o<<1|1])
 
    for(int i=1;i<maxl;i++)t[o][i]=t[o<<1][i]+t[o<<1|1][i];
 
}
 
void pd(int o,int l,int r){
 
    if(!add[o])return;
 
    if(l==r){
 
        for(;add[o]--;t[o][0]=nxt[t[o][0]]);add[o]=0;
 
        if(cir[t[o][0]]){
 
            tag[o]=1;
 
            for(int i=1;i<maxl;i++)t[o][i]=nxt[t[o][i-1]];
 
        }return;
 
    }
 
    int mid=l+r>>1;
 
    add[o<<1]=add[o<<1]+add[o],add[o<<1|1]=add[o<<1|1]+add[o];
 
    if(tag[o<<1]){
 
        for(int i=0;i<maxl;i++)tmp[i]=t[o<<1][mod[add[o]+i]];
 
        memcpy(t[o<<1],tmp,sizeof(tmp));
 
    }
 
    else pd(o<<1,l,mid);
 
    if(tag[o<<1|1]){
 
        for(int i=0;i<maxl;i++)tmp[i]=t[o<<1|1][mod[add[o]+i]];
 
        memcpy(t[o<<1|1],tmp,sizeof(tmp));
 
    }
 
    else pd(o<<1|1,mid+1,r);
 
    add[o]=0;mt(o);
 
}
 
void bt(int o,int l,int r){
 
    if(l==r){
 
        if(cir[t[o][0]=F()]){
 
            tag[o]=1;
 
            for(int i=1;i<maxl;i++)t[o][i]=nxt[t[o][i-1]];
 
        }return;
 
    }
 
    int mid=l+r>>1;
 
    bt(o<<1,l,mid),bt(o<<1|1,mid+1,r);
 
    mt(o);
 
}
 
void upd(int o,int l,int r){
 
    if(x<=l&&r<=y){
 
        add[o]++;
 
        if(tag[o]){
 
            for(int i=0;i<maxl;i++)tmp[i]=t[o][mod[i+1]];
 
            memcpy(t[o],tmp,sizeof(tmp));
 
        }
 
        else pd(o,l,r);
 
        return;
 
    }
 
    int mid=l+r>>1;pd(o,l,r);
 
    if(x<=mid)upd(o<<1,l,mid);
 
    if(mid<y)upd(o<<1|1,mid+1,r);
 
    mt(o);
 
}
 
void query(int o,int l,int r){
 
    if(x<=l&&r<=y){
 
        ans+=t[o][0];
 
        return;
 
    }
 
    int mid=l+r>>1;pd(o,l,r);
 
    if(x<=mid)query(o<<1,l,mid);
 
    if(mid<y)query(o<<1|1,mid+1,r);
 
}
 
int main(){
 
    for(n=F(),m=F(),p=F();i<p;i++)nxt[i]=i*i%p;
 
    for(i=0;i<p;i++){
 
        for(++tim,x=i,y=1;vis[x]!=tim;x=nxt[x])vis[x]=tim,cnt[x]=y++;
 
        if(maxl<y-cnt[x])maxl=y-cnt[x];
 
        for(;!cir[x];x=nxt[x])cir[x]=1;
 
    }
 
    for(i=0;i<=m;i++)mod[i]=i%maxl;
 
    for(bt(1,1,n);m--;)
 
    if(F())ans=0,x=F(),y=F(),query(1,1,n),printf("%d\n",ans);
 
    else x=F(),y=F(),upd(1,1,n);
 
}