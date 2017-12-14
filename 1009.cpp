#include <iostream>
 
#include <iomanip>
 
using namespace std;
 
int main(){
 
	int m,n;
 
	cin>>m;
 
	int trade_time[m],trade_num[m],trade_state[m];
 
	for(int i=0;i<m;++i)
 
		cin>>trade_time[i]>>trade_num[i]>>trade_state[i];
 
	cin>>n;
 
	int change_time[n],change_money[n];
 
	for(int i=0;i<n;++i)
 
		cin>>change_time[i]>>change_money[i];
 
	int i=0,j=0,per_money;
 
	double income=0.0;
 
	for(;i<m;++i){
 
		for(j=0;j<n-1;++j)
 
			if(change_time[j]<=trade_time[i]&&change_time[j+1]>trade_time[i])
 
				break;
 
		per_money=trade_num[i]*change_money[j]*100;
 
		income+=(trade_state[i]*2-3)*per_money;
 
		income-=((per_money*0.002)>5?(per_money*0.002):5);
 
		income-=trade_num[i]/10.0;
 
		income-=1;
 
		income-=(trade_state[i]-1)*per_money*0.001;
 
	}
 
    cout<<fixed<<setprecision(2)<<income<<endl;
 
}
