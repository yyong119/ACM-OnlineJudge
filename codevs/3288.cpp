#include <iostream>
using namespace std;
long long a[100001],b[100001];
long long i,ans,n,tail;
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	tail=1; b[tail]=a[1];
	for (i=2;i<=n;i++){
		if (a[i]>=b[tail]){
			tail++;
			b[tail]=a[i];
		}
		else{
			ans=ans+b[tail]-b[1];
			tail=1;
			b[tail]=a[i];
		}
	}
	cout<<ans+a[1]+b[tail]-b[1]<<endl;
	return 0;
}