#include <iostream>
using namespace std;

class heap {
private:
    int *data;
    int maxSize;
    int size;

    void doubleSpace() {
        int *tmp = data;
        data = new int[maxSize * 2 + 1];
        for (int i = 1; i <= size; ++i) data[i] = tmp[i];
        delete[]tmp;
        maxSize *= 2;
    }

public:
    heap(int capacity = 10) : maxSize(capacity), size(0), data(new int[capacity + 1]) {}
    ~heap() {
    	delete [] data;
    }
    void enQueue(int n) {
        if (size == maxSize) doubleSpace();
        int hole = ++size;
        for (; hole > 1 && n < data[hole >> 1]; hole = hole >> 1) data[hole] = data[hole >> 1];
        data[hole] = n;
    }
    int find(int t, int n) {
        if (t > size) return 0;
        if (data[t] > n) return t;
        int l = find(t << 1, n), r = find((t << 1) + 1, n);
        if (l&&r) {
            if (data[l] == data[r]) return (l < r ?  l : r);
            else return (data[l] < data[r] ? l : r);
        }
        else if (l) return l;
        else if (r) return r;
        else return 0;
    }
    void decrease(int i, int d) {
        int tmp = data[i] - d;
        for (; i > 1 && tmp < data[i >> 1]; i = i >> 1) data[i] = data[i >> 1];
        data[i] = tmp;
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
        case 'f':
            cin >> n;
            cout << h.find(1, n) << endl;
            break;
        case 'd':
            cin >> n >> m;
            h.decrease(n, m);
        }
    }
    return 0;
}