#include <iostream>
#include <queue>
 
using namespace std;
struct treedata{
    int l, r, pre;
} tree[1000001];
int n, i, node, now;
queue<int> que;
 
int main(){
    cin>>n;
    for (int i = 1; i < n; i++){
        cin>>node;
        tree[i].pre = node;
        if (tree[node].l == 0) tree[node].l = i;
        else tree[node].r = i;
    }
    cout<<0;
    if (tree[0].l) que.push(tree[0].l);
    if (tree[0].r) que.push(tree[0].r);
    while (!que.empty()){
        now = que.front();
        que.pop();
        cout<<" "<<now;
        if (tree[now].l) que.push(tree[now].l);
        if (tree[now].r) que.push(tree[now].r);
    }
    return 0;
}