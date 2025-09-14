#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int n, k, a[N], ans;

bool check(int len) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += a[i] / len;
    }
    return cnt >= k;
}

int main() {
    int l = 1, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), r = max(r, a[i]);
    scanf("%d", &k);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
