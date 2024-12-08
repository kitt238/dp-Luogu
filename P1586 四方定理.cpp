#include<iostream>
#include<cstring>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int t;
int dp[5][40000] = { 1 };

signed main() {
	cin >> t;
	for (int k = 1; k * k <= 32768; k++) {
		for (int i = 1; i <= 4; i++) {
			for (int j = k*k; j <= 32768; j++) {
				dp[i][j] += dp[i - 1][j - k*k];
			}
		}
	}
	while (t--) {
		int x;
		cin >> x;
		int ans = 0;
		for (int i = 1; i <= 4; i++) {
			ans += dp[i][x];
		}
		cout << ans<<endl;
	}
	return 0;
}
