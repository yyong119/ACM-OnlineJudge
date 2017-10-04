#include <iostream>
#include <queue>
 
using namespace std;
struct treedata{
    int l, r, pre;
} tree[1000001];
int n, i, node, now;
bool flag,complete = true;
queue<int> que;
 
int main(){
    cin>>n;
    for (int i = 1; i < n; i++){
        cin>>node;
        tree[i].pre = node;
        if (tree[node].l == 0) tree[node].l = i;
        else tree[node].r = i;
    }
    if (tree[0].l) que.push(tree[0].l);
    if (tree[0].r) que.push(tree[0].r);
    while (!que.empty()){
        now = que.front();
        que.pop();
        if (!tree[now].l&&!tree[now].r) flag = true;
        if (tree[now].l){
            que.push(tree[now].l);
            if (flag){
                complete = false;
                break;
            }
        }
        if (tree[now].r) que.push(tree[now].r);
    }
    if (complete) cout<<"true"; else cout<<"false";
    return 0;
}