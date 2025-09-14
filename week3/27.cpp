#include <bits/stdc++.h>
using namespace std;
const int N=110;
int A[N], B[N], dp[N], ndp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int tc = 1;
    while ( (cin >> n >> m) ) {
        if(n==0 && m==0) break;
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int j = 0; j < m; ++j) cin >> B[j];

        memset(dp, 0, sizeof(dp));
        memset(ndp, 0, sizeof(ndp));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i-1] == B[j-1]) ndp[j] = dp[j-1] + 1;
                else ndp[j] = max(dp[j], ndp[j-1]);
            }
            for (int j = 0; j <= m; ++j) dp[j]=ndp[j], ndp[j] = 0;
        }
        cout << "Twin Towers #" << tc++ << '\n';
        cout << "Number of Tiles : " << dp[m] << '\n';
    }

    return 0;
}
