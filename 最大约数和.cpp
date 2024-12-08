#include<iostream>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int S[2000];

int yue(int n) {
	int sum = -n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			sum += i;
			if (i * i != n)
				sum += n / i;
		}
	}
	return sum;
}

signed main() {
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++) {
		S[i] = yue(i);
		for (int j = 1; j <= i / 2; j++) {
			S[i] = max(S[j]+S[i-j], S[i]);
		}
	}
	cout << S[x];
	return 0;
}
