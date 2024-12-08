#include<iostream>
using namespace std;

int coin[6000000] = {0,1,2,3,4,1,2,3,4,5,2,1};

int min(int a,int b,int c) {
	int x=a;
	if (x > b)x = b;
	if (x > c)x = c;
	return x;
}

int minf(int n) {
	while (!coin[n]) {
		coin[n] = min(minf(n-1),minf(n-5),minf(n-11)) + 1;
	}
	return coin[n];
}

int main() {
	int n;
	cin >> n;
	minf(n);
	cout << coin[n];
	return 0;
}