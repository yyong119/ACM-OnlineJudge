#include <iostream>
using namespace std;

int mid(int a, int b, int c) {
	if (a < b) {
		if (b < c)return b;
		else if (c < a) return a;
		else return c;
	}
	else {
		if (a < c) return a;
		else if (c < b) return b;
		else return c;
	}
}

void partition(int arr[], int begin, int end, int& newEnd, int& newBegin) {
	int pivot = mid(arr[begin], arr[end], arr[(begin + end) / 2]);
	int pos = begin;
	while (pos <= end)
		if (arr[pos] < pivot) {
			int tmp = arr[pos];
			arr[pos++] = arr[begin];
			arr[begin++] = tmp;
		}
		else if (arr[pos] > pivot) {
			int tmp = arr[pos];
			arr[pos] = arr[end];
			arr[end--] = tmp;
		}
		else ++pos;
	newEnd = begin - 1;
	newBegin = end + 1;
}

void quick_sort(int arr[], int begin, int end) {
	if (begin < end) {
		int newEnd, newBegin;
		partition(arr, begin, end, newEnd, newBegin);
		quick_sort(arr, begin, newEnd);
		quick_sort(arr, newBegin, end);
	}
}

class set {
	friend istream& operator >> (istream &is, set& s) {
		for (int i = 0; i < s.size; ++i)
			is >> s.data[i];
		return is;
	}
	friend ostream& operator<<(ostream &os, const set& s) {
		for (int i = 0; i < s.size; ++i) os << s.data[i] << ' ';
		return os;
	}
private:
	int *data;
	int size;
	int maxSize;

	int find(int n) const {
		int l = 0, r = size - 1;
		while (l <= r) {
			if (data[l] >= n) break;
			int mid = (l + r) / 2;
			if (data[mid] < n)l = mid + 1;
			else r = mid;
		}
		return l;
	}
public:
	set(int sz, int cp = 10000) :size(sz), maxSize(cp) { data = new int[maxSize]; }
	~set() { delete[]data; }
	void operator+(const set& other) {
		for (int i = 0; i < other.size; ++i) {
			int pos = find(other.data[i]);
			if (pos == size)data[size++] = other.data[i];
			else if (data[pos] > other.data[i]) {
				for (int j = size++; j > pos; --j) data[j] = data[j - 1];
				data[pos] = other.data[i];
			}
		}
	}
	void operator-(const set& other) {
		for (int i = 0; i < other.size; ++i) {
			int pos = find(other.data[i]);
			if (pos < size&&data[pos] == other.data[i]) {
				for (int j = pos; j < size - 1; ++j) data[j] = data[j + 1];
				--size;
			}
		}
	}
	void operator*(const set& other) {
		int *tmp = new int[maxSize];
		int cnt = 0;
		int i, j;
		quick_sort(other.data, 0, other.size - 1);
		if (other.size > 0) i = find(other.data[0]);
		for (j = 0; j < other.size; ++j) {
			for (; i < size; ++i)
				if (data[i] >= other.data[j]) break;
			if (i == size) break;
			else if (data[i] == other.data[j]) tmp[cnt++] = data[i];
		}
		delete[]data;
		data = tmp;
		size = cnt;
	}
};

int main() {

	ios::sync_with_stdio(false);
	int n; cin >> n;
	set s(0);
	int m; char c;
	for (int i = 0; i < n; ++i) {
		cin >> c >> m;
		set s2(m);
		cin >> s2;
		switch (c) {
			case '+':
				s + s2;
				cout << s << '\n';
				break;
			case '-':
				s - s2;
				cout << s << '\n';
				break;
			case '*':
				s * s2;
				cout << s << '\n';
		}
	}
	return 0;
}