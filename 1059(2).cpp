#include <bits/stdc++.h>
using namespace std;

#define INF (1<<30)
#define ll long long
#define sz(x) ((int) (x.size()))
#define clr(x) memset(x, 0, sizeof(x))
ll power(ll x,ll y,ll mod){if (y<0)return power(power(x,mod-2,mod),-y,mod);ll res=1;while(y){if (y&1) res=res*x%mod;y>>=1;x=x*x%mod;}return res;}

const int nn = 2010;
int N;
int a[nn];
int es;
int other[nn], next[nn], g[1000010];
const int mod = 999997;

void insert(int x) {
	int t = x % mod;
	other[++es] = x; next[es] = g[t]; g[t] = es;
}

int find(int x) {
	
	int t = x % mod, s = 0;
	for (int p = g[t]; p; p = next[p]) {
		if (other[p] == x) s++;
	}
	return s;
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}
	ll res = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j) {

			int t = (ll) a[i] * a[j] % 100000000;
			res += find(t);
			if (t == a[i]) res--;
			if (t == a[j]) res--;
		}

	cout << res * 2 << endl;

	return 0;
}