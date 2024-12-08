#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n;
int dp[400];

signed main() {
	cin >> n;
	int sum = n * (n + 1) / 2;
	if (sum % 2 != 0) {
		cout << 0;
		return 0;
	}
	sum /= 2;
	dp[0] = 1,dp[1] == 1;
	for (int i = 2; i <= n; i++) {//从第二行开始
		for (int j = sum; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	cout << dp[sum];
	return 0;
}
