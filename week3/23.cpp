#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
char g[N][N];
int vis[N][N][55]; // 记录(x,y,时间%k)是否访问过
int n, m, k, sx, sy, ex, ey;

struct Node {
    int x, y, t;
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%s", g[i]);
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'S') sx = i, sy = j;
                if (g[i][j] == 'E') ex = i, ey = j;
            }
        }
        memset(vis, 0, sizeof(vis));
        queue<Node> q;
        q.push({sx, sy, 0});
        vis[sx][sy][0] = 1;
        int ans = -1;
        while (!q.empty()) { //BFS
            Node u = q.front(); q.pop();
            if (u.x == ex && u.y == ey) {
                ans = u.t;
                break;
            }
            for (int d = 0; d < 4; ++d) {
                int nx = u.x + dx[d], ny = u.y + dy[d], nt = u.t + 1;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == '#') continue;
                if (g[nx][ny] == '*' && nt % k != 0)  continue; // 怪物格子只有在消失时能走
                if (!vis[nx][ny][nt % k]) {
                    vis[nx][ny][nt % k] = 1;
                    q.push({nx, ny, nt});
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}