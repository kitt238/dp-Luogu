#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int n, m;
int a[102];
int rec[102][102];
int zero = 0;

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];  
	}
	for (int i = 0; i <= n; i++) {
		rec[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = j; k >=max(j- a[i],(int)0); k--) {
				rec[i][j] += rec[i - 1][k];
				rec[i][j] %= 1000007;
			}
		}
	}
	cout << rec[n][m];
	return 0;
}
