#include <iostream>
#include <cstdio>
using namespace std;
struct treedata{
    int l, r, pre;
} tree[1024];
int n, i, node, lt, rt, father, maxlevel;
int le[1024][1000];
void cengci(int node,int level){
    if (level > maxlevel) maxlevel = level;
    le[level][++le[level][0]] = node;
    if (tree[node].l) cengci(tree[node].l, level + 1);
    if (tree[node].r) cengci(tree[node].r, level + 1);
}
int main(){
    scanf("%d", &n);
    while (scanf("%d%d%d", &node, &lt, &rt) != EOF){
        tree[node].l = lt;
        tree[node].r = rt;
        tree[rt].pre = node;
        tree[lt].pre = node;
    }
    for (i = 1; i <= n; i++)
        if (!tree[i].pre){
            father = i;
            break;
        }
    cengci(father,1);
    for (i = 1; i <= maxlevel; i++){
        for (int j = 1; j <= 1000; j++)
            if (le[i][j]) cout<<le[i][j]<<endl;
            else break;
    }
    return 0;
}