#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int v, n;
int a[31];
int rec[31][20005];

int dp(int m, int sumv) {
	if (rec[m][sumv])return rec[m][sumv];
	if (m == 0 || sumv == 0)return 0;
	if (a[m] > sumv)rec[m][sumv] = dp(m - 1, sumv);
	else rec[m][sumv] = max(dp(m - 1, sumv), dp(m - 1, sumv - a[m]) + a[m]);
	return rec[m][sumv];
}

signed main() {
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout <<v- dp(n, v);
	return 0;
}
