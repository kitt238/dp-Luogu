#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int v, n, c;
int vx[10002], cx[10002];
int minC[10002];
int Ved[10002];

signed main() {
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> vx[i] >> cx[i];
	}
	for (int i = 1; i <= v; i++) {
		minC[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 1; j--) {
			if (j >= vx[i])//i体积当前小于所需体积
				minC[j] = min(minC[j], minC[j - vx[i]] + cx[i]);
			else//i体积大于所需体积
				minC[j] = min(minC[j], cx[i]);
		}
	}
	if (minC[v] <= c)cout << c-minC[v];
	else cout << "Impossible";
	return 0;
}
