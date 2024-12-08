#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int long long
#define INF 0x7fffffff
using namespace std;

int h, t, n;
int hh[55], tt[55],kk[55];
int dp[405][405];

signed main() {
	cin >> h >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> hh[i] >> tt[i] >> kk[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = h; j >= hh[i]; j--) {
			for (int y = t; y >= tt[i]; y--) {
				dp[j][y] = max(dp[j][y], dp[j - hh[i]][y - tt[i]] + kk[i]);
			}
		}
	}
	cout << dp[h][t];
	return 0;
}