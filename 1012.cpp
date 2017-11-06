#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 200007;
int d[maxn];
long long cnt[maxn], times[maxn];

int main() {

    int s, t;
    cin >> s >> t;
    memset(cnt, 0, sizeof(cnt));
    int tmp, ans = 1;
    cnt[1] = t - s + 1;

    for (int i = s; i <= t; ++i) d[i] = times[i] = 1;

    for (int i = s; i <= t; ++i) 
    	for (int j = 1; j <= 100; ++j)
    		if ((i*j)%100 == 0) {
	            tmp = i + i * j / 100;
	            if (tmp <= t) {
	                if(d[i] + 1 > d[tmp]) {
	                    d[tmp] = d[i] + 1;
	                    times[tmp] = times[i];
	                }
	                else if(d[i] + 1 == d[tmp]) times[tmp] += times[i];
	                ans = max(ans, d[tmp]);
	                cnt[d[i] + 1] += times[i]; 
	            }
	        } 
    cout << ans << endl << cnt[ans];    
    return 0;
}