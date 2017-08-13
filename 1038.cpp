#include <iostream>
using namespace std;
int K[10000]={0};
int main()
{
    int M;
    cin>>M;
    int ans = 0;
 
    for (int i = 1; i <= M-1; ++i){
        cin>>K[i];
    }
 
    for (int i = 2; i <= M; ++i)
    {
        ans = (ans+K[M-i+1]) % i;
    }    
    cout<<ans+1<<endl;
    return 0;
}