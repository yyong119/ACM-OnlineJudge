#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define MAXN 1000009
#define Inf 0x7FFFFFFF
#define FIR 1
#define SEC 2
vector< int > fir[ MAXN ];
int clr[ MAXN ], sum[ MAXN ][2], val[ MAXN ], d[ MAXN ], path[ MAXN ], q[ MAXN ];
bool leaf[ MAXN ];
int N;
void DYE(int rt)
{
	int u;
	q[0] = 0;
	q[ ++q[0] ] = rt;
	for (int i = 1; i <= q[0]; i++) {
		u = q[i];
		for (int j = 0; j != (int) fir[u].size(); j++) 
			if (!clr[ fir[u][j] ]) {
				path[ fir[u][j] ] = u;
				clr[ fir[u][j] ] = 3 - clr[u];
				q[ ++q[0] ] = fir[u][j];
			}
	}
	return ;
}
void BFS()
{
	int u, v;
	q[0] = 0;
	for (int i = 1; i <= N; i++) {
		sum[i][0] = Inf, sum[i][1] = 0;
		d[i] = fir[i].size();
		if (d[i] == 0) {
			q[ ++q[0] ] = i; 
			sum[i][0] = 0;
		}
	}
	
	for (int i = 1; i <= q[0]; i++) {
		v = q[i], u = path[v];
		sum[v][0] += val[v];
		if (clr[v] == FIR) {
			if (sum[v][1] < sum[u][0] || (sum[v][1] == sum[u][0] && sum[v][0] > sum[u][1]))
				sum[u][0] = sum[v][1], sum[u][1] = sum[v][0];
		}
		else {
			if (sum[v][0] > sum[u][1] || (sum[v][0] == sum[u][1] && sum[v][1] < sum[u][0]))
				sum[u][0] = sum[v][1], sum[u][1] = sum[v][0];
		}
		if (!--d[u]) q[ ++q[0] ] = u;
	}
	return ;
}

int main()
{
    int u, v;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &u, &v);
        fir[u].push_back(v);
        leaf[v] = true;
    }
    int root;
    for (int i = 1; i <= N; i++)
        if (!leaf[i]) {
            root = i;
            break;
        }

    clr[ root ] = FIR;
	DYE( root );
	BFS();
    printf("%d %d\n", sum[ root ][0], sum[ root ][1]);
    return 0;
}