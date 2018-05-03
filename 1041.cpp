#include <iostream>
#include <algorithm>
#define ERRORNUM 0x7fffffff
using namespace std;
const int SIZE = 100010;
int plane[SIZE];
pair<int, int> heap[SIZE];
int N;

void MinHeap(int pos) {

	pair<int, int> tmp;
	for (; pos > 1 && heap[pos >> 1] > heap[pos]; pos >>= 1) {
		tmp = heap[pos >> 1];
		heap[pos >> 1] = heap[pos];
		heap[pos] = tmp;
	}
}

void Maintain(int planeIndex, int decrease_height) {

	int pos = plane[planeIndex];
	pair<int, int> tmp;
	heap[pos].first -= decrease_height;
	for (; pos > 1 && heap[pos >> 1] > heap[pos]; pos >>= 1) {
		tmp = heap[pos >> 1];
		heap[pos >> 1] = heap[pos];
		heap[pos] = tmp;
		plane[heap[pos].second] = pos;
		plane[heap[pos >> 1].second] = pos >> 1;
	}
}

int FindMin(int min_height, int root_pos = 1) {

	if (root_pos > N) return ERRORNUM;
	if (heap[root_pos].first > min_height) return heap[root_pos].second;
	return min(FindMin(min_height, root_pos << 1), FindMin(min_height, root_pos << 1 | 1));
}

int main() {

	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> heap[i].first;
		heap[i].second = i;
		MinHeap(i);
	}
	for (int i = 1; i <= N; ++i) plane[heap[i].second] = i;
	char op[10];
	while (cin >> op) {
		if (op[0] == 'd') {
			int planeIndex, decrease_height;
			cin >> planeIndex >> decrease_height;
			Maintain(planeIndex, decrease_height);
		}
		else {
			int min_height;
			cin >> min_height;
			int planeIndex = FindMin(min_height);
			cout << planeIndex << '\n';
		}
	}
	return 0;
}
