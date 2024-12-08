#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int dp[50005];
int n,h, p[102], c[102];

signed main() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
	}
	for (int i = 1; i <= h; i++) {
		dp[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= h; j++) {
			if (j < p[i]) 
				dp[j] = min(dp[j], c[i]);
			else
				dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
		}
	}
	cout << dp[h];
	return 0;
}
