#include <bits/stdc++.h>
using namespace std;
const int MOD = 10000000;
const int N=2020;
const int M=100010;
int n, V,p[N],dp[M],ndp[M];
int main() {
    cin >> n >> V;
    for (int i = 0; i < n; ++i) cin >> p[i];
    dp[0] = 1; 
    for (int i = 0; i < n; ++i)
    {
        int add = ((p[i] % V) + V) % V;
        for (int j = 0; j < V; ++j) ndp[j] = dp[j];
        for (int j = 0; j < V; ++j) {
            if(!dp[j]) continue;
            int to = j + add;
            if (to >= V) to -= V;
            ndp[to] += dp[j];
            if (ndp[to] >= MOD) ndp[to] -= MOD * (ndp[to] / MOD);
        }
        // for(int j=0;j<V;j++) printf("%d ",ndp[j]);
        // printf("\n");
        for (int j = 0; j < V; ++j) dp[j] = ndp[j],ndp[j] = 0;
    }

    cout << (dp[0]+MOD-1) % MOD << '\n';
    return 0;
}
/*
0 1
0 1 2 3
0 1 2 3 3 4 0 1
0 1 2 3 3 4 0 1 2 3 4 5 5
*/
