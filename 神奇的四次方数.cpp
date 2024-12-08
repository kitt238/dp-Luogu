#include<iostream>
#include<cmath>
#define int long long
#define Inf 0x7fffffff
using namespace std;

int dp[100005];

signed main() {
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        dp[i] = i;
    }
    for (int i = 1; i*i*i*i <= m; i++) {
        int i4 = pow(i, 4);
        for (int j = i4; j <= m; j++) {
            dp[j] = min(dp[j], dp[j - i4] + 1);
        }
    }
    cout << dp[m];
    return 0;
}