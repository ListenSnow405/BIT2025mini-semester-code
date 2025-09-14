#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=30010;
ll dp[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int t, w;
        cin >> t >> w;
        long long val = 1LL * t * w;
        if (t > n) continue; 
        for (int cap = n; cap >= t; --cap) {
            long long cand = dp[cap - t] + val;
            if (cand > dp[cap]) dp[cap] = cand;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; ++i)  ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}