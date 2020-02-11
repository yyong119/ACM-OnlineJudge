#include <cstdio>
#define MAX_T 1010000
#define MAX_N 15
using namespace std;

bool possible[MAX_T];
int card[MAX_N], n;

int main(){
    scanf("%d", &n);
	for (register int i = 0; i < n; ++i) {
        scanf("%d", &card[i]);
		if (card[i] == 1) {
            printf("0\n");
			return 0;
		}
		possible[card[i]] = 1;
	}
	for (register int i = 0; i < MAX_T; ++i)
		if (possible[i])
			for (register int j = 0; j < n; ++j)
				possible[i + card[j]] = 1;
	register int i;
	for (i = 1000000 ;possible[i]; --i);
	if (i > 100000) printf("0\n");
	else printf("%d\n", i);
	return 0;
}