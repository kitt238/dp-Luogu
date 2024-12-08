#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int t, m;
int a[10005], b[10005];
int dp[10000007];

signed main() {
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = a[i]; j <= t; j++) {
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	cout << dp[t];
	return 0;
}
