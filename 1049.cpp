#include<cstdio>
#include<stack>
using namespace std;
int M, N;
const int SIZE = 1010;
int order[SIZE];
 
int main() {
 
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
 
		for (int i = 0; i < N; ++i) scanf("%d", &order[i]);
 
		stack<int> ControlStation;
		int i = 0, j = 0;
		bool ok = true;
		while (j < N) {
			if (i == order[j]) {
				i++; j++;
			}
			else
			if (!ControlStation.empty() && ControlStation.top() == order[j]) {
				ControlStation.pop(); j++;
			}
			else
			if (i < N && ControlStation.size() < M)
				ControlStation.push(i++);
			else {
				ok = false; break;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}