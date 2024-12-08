#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int T, M;
int t[105], v[105];
int f[105][1005];

int dp(int m, int sumt) {
	if (f[m][sumt])return f[m][sumt];
	if (m == 0||sumt==0)return 0;
	if (sumt < t[m])f[m][sumt] = dp(m - 1, sumt);
	else f[m][sumt] = max(dp(m - 1, sumt), dp(m - 1, sumt - t[m]) + v[m]);
	return f[m][sumt];
}

signed main() {
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> v[i];
	}
	cout << dp(M,T);
	return 0;
}
