#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int s, n, d;
int a[12], b[12];
int dp[1000006];

signed main() {
	cin >> s >> n >> d;
	for (int i = 1; i <= d; i++) {
		cin >> a[i] >> b[i];
		a[i] /= 1000;
	}
	for (int i = 1; i <= d; i++) {
		for (int j = a[i]; j <= 46 * s / 1000; j++) {
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	int it = s;
	for (int i = 1; i <= n; i++) {
		it += dp[it / 1000];
	}
	cout << it;
	return 0;
}
