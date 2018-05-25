#include <iostream>
using namespace std;

bool visited[10005];
int last[10005];

struct edgeNode {
	int end, weight;
	edgeNode *next;

	edgeNode(int e, int w, edgeNode* p = NULL) : end(e), weight(w), next(p) {}
};

class adjList {

private:

	edgeNode **verList;
	int vers;

public:

	adjList(int sz) : vers(sz), verList(new edgeNode * [sz + 1]()) {}
	~adjList() {
		for (int i = 1; i <= vers; ++i) {
			edgeNode *p = verList[i];
			while (p) {
				edgeNode *q = p->next;
				delete p;
				p = q;
			}
		}
		delete[]verList;
	}
	void insert(int u, int v, int w) {
		verList[u] = new edgeNode(v, w, verList[u]);
	}
	edgeNode* vat(int i) {
		return verList[i];
	}
};

struct vertex {

	int num, distance, edges;

	vertex() : distance(0x7fffffff), edges(0) {}
	bool operator<(const vertex& v) {
		return distance < v.distance || distance == v.distance && edges < v.edges;
	}
};

void percolateDown(vertex arr[], int hole, int size) {
	vertex tmp = arr[hole];
	int child;
	for (; (hole << 1) <= size; hole = child) {
		child = hole << 1;
		if (child + 1 <= size && arr[child + 1] < arr[child])++child;
		if (arr[child] < tmp)arr[hole] = arr[child];
		else break;
	}
	arr[hole] = tmp;
}

void ins(vertex arr[], vertex v, int size) {

	int hole = ++size;
	for (; hole > 1 && v < arr[hole >> 1]; hole = hole >> 1) arr[hole] = arr[hole >> 1];
	arr[hole] = v;
}

int heapSize;
vertex arr[200005];

void printPath(int start, int end, int last[]) {

	if (start == end) {
		cout << start << ' ';
		return;
	}
	printPath(start, last[end], last);
	cout << end << ' ';
}

int main() {

	ios::sync_with_stdio(false);
	int n, m, start, end;
	cin >> n >> m >> start >> end;

	vertex result[10005];

	for (int i = 1; i <= n; ++i) result[i].num = arr[i].num = i;
	result[start].distance = 0;
	heapSize = n;
	arr[1].num = start;
	arr[start].num = 1;
	last[start] = start;
	adjList graph(n);
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		graph.insert(u, v, w);
	}
	while (heapSize > 0) {
		vertex pop = arr[1];
		arr[1] = arr[heapSize--];
		percolateDown(arr, 1, heapSize);
		if (!visited[pop.num]) {
			int vnum = pop.num;
			visited[vnum] = true;
			edgeNode *p = graph.vat(vnum);
			while (p) {
				if (!visited[p->end] && (result[vnum].distance + p->weight < result[p->end].distance || result[vnum].distance + p->weight == result[p->end].distance && result[vnum].edges + 1 < result[p->end].edges)) {
					vertex tmp;
					tmp.distance = result[vnum].distance + p->weight;
					tmp.edges = result[vnum].edges + 1;
					tmp.num = p->end;
					result[p->end] = tmp;
					ins(arr, tmp, heapSize++);
					last[p->end] = vnum;
				}
				p = p->next;
			}
		}
		if (visited[end]) break;
	}
	cout << result[end].distance << '\n';
	printPath(start, end, last);
	return 0;
}
