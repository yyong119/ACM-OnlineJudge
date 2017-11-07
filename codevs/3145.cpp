#include<iostream>
#include<stack>
using namespace std;
stack<int>st [3] ;
int chti(char ch)
{
switch(ch)
{
case 'A':return 0;
case 'B':return 1;
case 'C':return 2;
}
}

void hanoi(int n,char one,char two,char three)
{
if(n==1)
{
cout<<st[chti(one)].top()<<" from "<<one<<" to "<<three<<"\n";
st[chti(three)].push(st[chti(one)].top());
st[chti(one)].pop();
}
else
{
hanoi(n-1,one,three,two);
cout<<st[chti(one)].top()<<" from "<<one<<" to "<<three<<"\n";
st[chti(three)].push(st[chti(one)].top());
st[chti(one)].pop();
hanoi(n-1,two,one,three);
}
}
int step(int n)
{
int ans=0,i;
for(i=1;i<=n;i++)
{
ans=ans*2+1;
}
return ans;
}

int main()
{
int n;
cin>>n;
for(int i=n;i>=1;i--)
{
st[0].push(i);
}
cout<<step(n)<<"\n";
hanoi(n,'A','B','C');
return 0;
}