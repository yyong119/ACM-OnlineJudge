#include <iostream>
#include <cstring>
#include <cstdio>
 
int father[200001], son[200001];
bool alive[200001];
char Data;
int n, i, num, a, b;
 
using namespace std;
 
void Solvedead(int Dindex) {
 
    if (alive[father[Dindex]] == false) {
        num += son[Dindex] - 1;
    } else {
        son[father[Dindex]] -= 1;
        num += son[Dindex];
    }
    father[Dindex] = Dindex;
    alive[Dindex] = false;
    printf("%d\n", num);
}
 
int main() {
    scanf("%d", &n);
	num = 1;
	father[1] = 1;
	memset(alive, true, sizeof(alive));
	for (i = 1; i <= n; i++) {
		scanf("%s", &Data);
		if (Data == 'B') {
			scanf("%d%d", &a, &b);
			father[b] = a;
			son[a] += 1;
		}
		else {
			scanf("%d", &a);
			Solvedead(a);
		}
	}
	return 0;
}