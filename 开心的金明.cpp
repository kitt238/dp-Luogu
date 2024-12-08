#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n, m;
int v[26], p[26];
int dp[300005];

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v[i] >> p[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
		}
	}
	cout << dp[n];
	return 0;
}
