#include<iostream>
#include<vector>
#include<cstring>
#define INF 0x7fffffff
#define int long long
using namespace std;

int dp[1002];
vector<int>prime;
int n;

bool isprime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return 0;
	}
	return 1;
}

void setprime() {
	for (int i = 2; i <= n; i++) {
		if ((prime.empty()||i>prime.back())&&isprime(i))prime.push_back(i);
	}
}

void solve() {
	memset(dp, 0, sizeof(dp));
	setprime();
	dp[0] = 1;
	for (int i = 0; i < prime.size(); i++) {
		for (int j = prime[i]; j <= n; j++) {
			dp[j] += dp[j - prime[i]];
		}
	}
	cout << dp[n]<<endl;
}

signed main() {
	while (cin >> n) {
		solve();
	}
	return 0;
}
