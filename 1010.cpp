#include <iostream>
int budget,rest,deposit,month,deadmonth;
int insufficiency;
int main(){
    using namespace std;
    insufficiency=0;
    for (month=1; month<=12; month++){
        rest+=300;
        cin>>budget;
        rest-=budget;
        if (rest>=100){
            deposit+=rest-rest%100;
            rest=rest%100;
        }
        if (rest<0){
            insufficiency++;
            if (insufficiency==1) deadmonth=month;
        }
    }
    if (insufficiency) cout<<"-"<<deadmonth;
        else cout<<rest+deposit*1.2;
    return 0;
}