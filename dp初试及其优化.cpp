#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n, m;
//int dp[120][10500];
int dp[10500];
int a[120];

//void f() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (j == a[i])dp[i][j] = dp[i - 1][j] + 1;
//			if (j > a[i])dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
//			if (j < a[i])dp[i][j] = dp[i - 1][j];
//		}
//	}
//}

//以下为只用一维数组代替二维数组的优化
void f() {
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--) {
			dp[j] = dp[j] + dp[j - a[i]];
		}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f();
	//cout << dp[n][m];
	cout << dp[m];
	return 0;
}