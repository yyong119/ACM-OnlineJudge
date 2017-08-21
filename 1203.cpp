#include <iostream>
using namespace std;
const int MAX_N = 10005;
int n, m;
 
class op {
	public:
		int a[MAX_N << 1];
		double b[MAX_N << 1];
		char c[MAX_N << 5];
};
 
op operator+(op p, op q) {
 
	op tmp;
	for (int i = 1; i <= n; ++i) {
		tmp.a[i] = p.a[i];
		tmp.b[i] = p.b[i];
		tmp.c[i] = p.c[i];
	}
	for (int i = 1; i <= m; ++i) {
		tmp.a[i + n] = q.a[i];
		tmp.b[i + n] = q.b[i];
		tmp.c[i + n] = q.c[i];
	}
	return tmp;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	char tmp[10];
	cin >> tmp;
	cin >> n >> m;
	op p, q, r;
	switch (tmp[0]) {
	case 'i':
		for (int i = 1; i <= n; ++i) cin >> p.a[i];
		for (int i = 1; i <= m; ++i) cin >> q.a[i];
		r = p + q;
		for (int i = 1; i <= n + m; ++i) cout << r.a[i] << " ";
		break;
	case 'd':
		for (int i = 1; i <= n; ++i) cin >> p.b[i];
		for (int i = 1; i <= m; ++i) cin >> q.b[i];
		r = p + q;
		for (int i = 1; i <= n + m; ++i) cout << r.b[i] << " ";
		break;
	case 'c':
		for (int i = 1; i <= n; ++i) cin >> p.c[i];
		for (int i = 1; i <= m; ++i) cin >> q.c[i];
		r = p + q;
		for (int i = 1; i <= n + m; ++i) cout << r.c[i] << " ";
		break;
	}
	return 0;
}