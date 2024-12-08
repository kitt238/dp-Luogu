#include<iostream>
#define INF 0x7fffffff
#define int long long			
#define MAX_N 1002
using namespace std;

int n, m;
int ractangle[MAX_N][MAX_N];

int add(int i, int j) {
	if (ractangle[i][j] == -1)return 0;
	else return ractangle[i][j];
}

signed main() {
	cin >> n >> m;
	ractangle[1][1] = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		ractangle[x][y] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ractangle[i][j] == -1||i==1&&j==1)continue;
			ractangle[i][j] = add(i - 1, j) + add(i, j - 1);
			ractangle[i][j] %= 100003;
		}
	}
	cout << ractangle[n][n];
	return 0;
}
