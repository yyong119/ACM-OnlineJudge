#include <iostream>
#include <cstring>
using namespace std;

class stack {
private:
	char *data;
	int topP, maxSize;

	void doubleSpace() {
		char *tmp = data;
		data = new char[maxSize * 2];
		for (int i = 0; i < maxSize; ++i)data[i] = tmp[i];
		maxSize *= 2;
		delete[] tmp;
	}
public:
	stack() :topP(-1), maxSize(10) {
		data = new char[maxSize];
	}
	bool empty() {
		return topP == -1;
	}
	void push(char c) {
		if (topP == maxSize - 1)doubleSpace();
		data[++topP] = c;
	}
	char pop() {
		if (!empty()) return data[topP--];
	}
	char top() {
		if (!empty()) return data[topP];
	}
};

int main() {

	ios::sync_with_stdio(false);
	stack v;
	char str[1000];
	bool isOk = true;
	while (cin >> str) {
		if (strcmp(str, "begin") == 0 || strcmp(str, "if") == 0)
			v.push(str[0]);
		else if (strcmp(str, "then") == 0) {
			if (v.empty() || v.pop() != 'i') isOk = false;
			else v.push('t');
		}
		else if (strcmp(str, "end") == 0) {
			do {
				if (v.empty() || v.top() == 'i') {
					isOk = false; break;
				}
				if (v.pop() == 'b')break;
			} while (true);
			if (!isOk)break;
		}
		else if (strcmp(str, "else") == 0) {
			if (v.empty() || v.pop() != 't') isOk = false;
		}
		if (!isOk) break;
	}
	while (isOk && !v.empty()) {
		if (v.pop() != 't') isOk = false;
	}
	if (isOk) cout << "Match!" << '\n';
	else cout << "Error!" << '\n';
	return 0;
}