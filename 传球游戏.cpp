#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n, m;
int a[2][32];

void add(int cnt, int p) {
	if (p == 0)
		a[cnt % 2][p] = a[(cnt - 1) % 2][p + 1] + a[(cnt - 1) % 2][n - 1];
	else if (p == n - 1)
		a[cnt % 2][p] = a[(cnt - 1) % 2][0] + a[(cnt - 1) % 2][p - 1];
	else
		a[cnt % 2][p] = a[(cnt - 1) % 2][p - 1] + a[(cnt - 1) % 2][p + 1];
}

signed main() {
	cin >> n >> m;
	a[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			add(i, j);
		}
	}
	cout << a[m % 2][0];
	return 0;
}
