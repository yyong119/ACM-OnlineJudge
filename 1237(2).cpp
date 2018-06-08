#include <iostream>
using namespace std;
 
struct edgeNode {
    int end;
    edgeNode *next;
 
    edgeNode(int e, edgeNode* p = NULL) :end(e), next(p) {}
};
 
class adjList {
private:
    edgeNode **verList;
    int vers;
public:
    adjList(int sz) :vers(sz),verList(new edgeNode*[sz + 1]()) {}
    ~adjList() {
        for (int i = 1;i <= vers;++i) {
            edgeNode *p = verList[i];
            while (p) {
                edgeNode *q = p->next;
                delete p;
                p = q;
            }
        }
        delete[]verList;
    }
    void insert(int u, int v) {
        verList[u] = new edgeNode(v,verList[u]);
    }
    edgeNode* vat(int i) {
        return verList[i];
    }
};
 
int main() {
	
    ios::sync_with_stdio(false);

    int n, m, a, b;
    cin >> n >> m;
    adjList graph(n);
    int inDegree[10005] = { 0 };
    int sem[10005] = { 0 };
    for (int i = 0;i < m;++i) {
        cin >> a >> b;
        graph.insert(a, b);
        ++inDegree[b];
    }
    int ans = 0;
    int q[10005];
    int front = 0, back = -1;
    for (int i = 1;i <= n;++i)
        if (inDegree[i] == 0) {
            q[++back] = i;
            sem[i] = 1;
        }
    int cur;
    while (front <= back) {
        cur = q[front++];
        if (sem[cur] > ans)ans = sem[cur];
        edgeNode *p = graph.vat(cur);
        while (p) {
            if (--inDegree[p->end] == 0) {
                q[++back] = p->end;
                sem[p->end] = sem[cur] + 1;
            }
            p = p->next;
        }
    }
    cout << ans << '\n';
    return 0;
}
