#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 20000

using namespace std;


struct Stock {
	int id, val;
};

bool cmp(Stock p, Stock q) {
	if (p.val == q.val) return p.id > q.id;
	return p.val < q.val;
}

int main () {
	int N, K, tmp, n1, n2;
	char ch;
	Stock s[MAX + 1];
	int pos[MAX + 1];

	scanf("%d", &N);
	for (int i = 1; i <= N; ++ i) {
		scanf("%d", &tmp);
		s[i].id = i;
		s[i].val = tmp;
		pos[i] = i;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++ i) {
		scanf("\n%c", &ch);
		switch (ch) {
		case 'M':
			scanf("%d%d", &n1, &n2);
			s[pos[n1]].val = n2;
			break;
		case 'Q':
			sort(s + 1, s + N + 1, cmp);
			for (int i = 1; i <= N; ++i) pos[s[i].id] = i;
			scanf("%d", &tmp);
			for (int j = 0; j < tmp; ++ j) {
				scanf("%d", &n1);
				printf("%d ", s[N + 1 - n1].id);
			}
			printf("\n");
			break;
		}
	}
}