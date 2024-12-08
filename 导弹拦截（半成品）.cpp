#include<iostream>
#include<cstdio>
#include<vector>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

vector<int>missle;
vector<int>down;

void binary(int i) {
	int l = 0, r = down.size();
	while (l < r) {
		int mid = (l + r) / 2;
		if (missle[down[mid]] < missle[i]) r = mid;
		else l = mid + 1;
	}
	if (r != down.size())down[r] = i;
	else down.push_back(i);
}

signed main() {
	int x;
	do {
		cin >> x;
		missle.push_back(x);
		binary(missle.size()-1);
	} while (getchar() != '\n');
	cout << down.size();
	return 0;
}
