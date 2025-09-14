#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
char g[N][N];
int n, m, k, sx, sy, ex, ey;
int dist[N][N];

struct Node {
    int x, y;
};
queue<Node> q;
int main()
{
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%s", g[i]);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    sx--; sy--; 
    ex--; ey--;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        Node u = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            for (int step = 1; step <= k; ++step) {
                int nx = u.x + dx[d] * step;
                int ny = u.y + dy[d] * step;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#' || dist[nx][ny] < dist[u.x][u.y] + 1) 
                    break;
                if (dist[nx][ny] == dist[u.x][u.y] + 1) 
                    continue; // 已经入队过
                dist[nx][ny] = dist[u.x][u.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    if (dist[ex][ey] == 0x3f3f3f3f) puts("-1");
    else printf("%d\n", dist[ex][ey]);
    return 0;
}