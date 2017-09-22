#include <iostream>
#include <queue>
 
using namespace std;
priority_queue <int, vector<int>, greater<int> > que;
long n, cost, temp;
 
int main() {
 
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        que.push(temp);
    }
 
    while (que.size() != 1) {
        temp = que.top(); que.pop();
        temp += que.top(); que.pop();
        cost +=temp; que.push(temp);
    }
    cout<<cost;
}