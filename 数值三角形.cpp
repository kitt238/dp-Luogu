#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n;
int tree[1005][1005];

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tree[i][j];
			tree[i][j] += max(tree[i - 1][j - 1], tree[i - 1][j]);
		}
	}
	int ans = -INF;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, tree[n][i]);
	}
	cout << ans;
	return 0;
}
