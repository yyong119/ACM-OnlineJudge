#include <iostream>
using namespace std;
 
class heap {
private:
	int *data;
	int maxSize;
	int size;
 
	void doubleSpace() {
		int *tmp = data;
		data = new int[maxSize << 1 | 1];
		for (int i = 1; i <= size; ++i) data[i] = tmp[i];
		delete [] tmp;
		maxSize <<= 1;
	}
 
	void maintain() {
		for (int i = size >> 1; i >= 1; --i) {
			if (data[i] > data[i << 1]) {
				int tmp = data[i]; data[i] = data[i << 1]; data[i << 1] = tmp;
			}
			if (data[i] > data[i << 1 | 1] && (i << 1 | 1) <= size) {
				int tmp = data[i]; data[i] = data[i << 1 | 1]; data[i << 1 | 1] = tmp;
			}
		}
	}
 
public:
	heap(int capacity = 10) : maxSize(capacity), size(0), data(new int[capacity + 1]) {}
	~heap() {
		delete[] data;
	}
	void enQueue(int n) {
		if (size == maxSize) doubleSpace();
		data[++size] = n;
		maintain();
	}
	int getMin() {
		return data[1];
	}
	void deleteMin() {
		data[1] = data[size--];
		maintain();
	}
};
 
int main() {
	ios::sync_with_stdio(false);
	heap h;
	int M; cin >> M;
	char op[10];
	int n, m;
	for (int i = 0; i < M; ++i) {
		cin >> op;
		switch (op[0]) {
		case 'i':
			cin >> n;
			h.enQueue(n);
			break;
		case 'd':
			h.deleteMin();
			break;
		case 'm':
			cout << h.getMin() << endl;
		}
	}
	return 0;
}