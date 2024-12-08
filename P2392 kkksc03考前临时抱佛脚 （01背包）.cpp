#include<iostream>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int s[5];//存放si的个数
int a[5][22];//存放si的具体元素
int dp[2500];
int ans = 0;

int close(int a, int b, int val) {
	int l = val / 2;
	int r = (val + 1) / 2;
	return abs(a - l) + abs(a - r) < abs(b - l) + abs(b - r) ? a : b;
}

int f(int k) {
	memset(dp, 0, sizeof(dp));
	int sum = 0;
	for (int i = 1; i <= s[k]; i++) {
		sum += a[k][i];
	}
	for (int i = 1; i <= s[k]; i++) {
		for (int j = sum; j >= a[k][i]; j--) {
			dp[j] = close(dp[j], dp[j - 2*a[k][i]] + a[k][i], j);
		}
	}
	return max(dp[sum],sum-dp[sum]);
}

signed main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 4; i++) {
		ans += f(i);
	}
	cout << ans;
	return 0;
}
