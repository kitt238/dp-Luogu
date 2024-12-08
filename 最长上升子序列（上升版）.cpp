#include<iostream>
using namespace std;

int main() {
	int num[6000];
	int L[6000];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		L[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		int maxl = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (num[j] < num[i]) {
				maxl = max(maxl, L[j] + 1);
			}
			L[i] = maxl;
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, L[i]);
	}
	cout << maxx;
	return 0;
}