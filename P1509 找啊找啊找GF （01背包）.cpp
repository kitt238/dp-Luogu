#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

struct MM{
	int time;
	int num;
}dp[102][102];

int n, rmb[102], rp[102], tim[102], m, r;

MM judge(MM a, MM b,int k) {
	MM temp;
	if (a.num != b.num+1) {
		if (a.num > b.num + 1) {
			temp.num = a.num;
			temp.time = a.time;
		}
		else {
			temp.num = b.num + 1;
			temp.time = b.time + tim[k];
		}
	}
	else {
		temp.num = a.num;
		temp.time = min(a.time, b.time + tim[k]);
	}
	return temp;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rmb[i] >> rp[i] >> tim[i];
	}
	cin >> m >> r;
	for (int k = 1; k <= n; k++) {
		for (int i = m; i >= rmb[k]; i--) {
			for (int j = r; j >= rp[k]; j--) {
				dp[i][j] = judge(dp[i][j], dp[i - rmb[k]][j - rp[k]],k);
			}
		}
	}
	cout << dp[m][r].time;
	return 0;
}
