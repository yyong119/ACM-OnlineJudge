#include <cstdio>
const int MAX_N = 1000010;
using namespace std;
long long _c[MAX_N];
#define low_bit(x) (x & (-x))
 
inline int read() {
 
	char ch; int ret = 0;
	for (ch = getchar(); ch<'0' || ch>'9'; ch = getchar());
	for (; ch >= '0'&& ch <= '9'; ret = ret * 10 + ch - '0', ch = getchar());
	return ret;
}
 
long long sum(long long _c[], int spot) {
 
	long long _sum = 0;
	while (spot > 0) {
		_sum += _c[spot];
		spot -= low_bit(spot);
	}
 
	return _sum;
}
 
int main() {
 
	int n, p;
//	scanf("%d%d", &n, &p);
	n = read(); p = read();
	int _num, _num2;
	long long _ans;
	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &_num);
		_num = read();
		int tmp = i;
		while (tmp <= n) {
			_c[tmp] += _num;
			tmp += low_bit(tmp);
		}
	}
 
	while (p--) {
//		scanf("%d%d", &_num, &_num2);
		_num = read(); _num2 = read();
		_ans = sum(_c, _num2) - sum(_c, _num - 1);
		printf("%lld\n", _ans);
	}
 
	return 0;
}