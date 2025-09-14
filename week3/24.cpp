#include <bits/stdc++.h>  
using namespace std;  
  
const int N = 2110;  
const int M = 2e5+10; 
const int INF = 0x3f3f3f3f;  
const int dx[4] = {1, -1, 0, 0};  
const int dy[4] = {0, 0, 1, -1};  
  
char g[N][N];  
int n, m;  
int sx , sy , tx , ty ,tot;  
struct node{ 
    int x,y; 
}q[M]; 
int distN[N][N];  
int distC[N][N];  
  
inline bool check(int x, int y) {  
    return x >= 0 && x < n && y >= 0 && y < m;  
}  
  
void bfs_from(int sx, int sy, int dist[][N], int &best) {  
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dist[i][j] = -1;  
    dist[sx][sy] = 0;  
    int hh=0,tt=0; 
    q[tt++] = {sx, sy};  
    while (hh != tt) {  
        int x= q[hh].x,y=q[hh].y; hh++;
        if(hh==M) hh=0; 
        int d = dist[x][y];  
        if(g[x][y] == 'E') {  
            best = min(best, d);  
        }
        for (int k = 0; k < 4; ++k) {  
            int nx = x + dx[k], ny = y + dy[k];  
            if (!check(nx, ny)) continue;  
            if (g[nx][ny] == 'M') continue;  
            if (dist[nx][ny] == -1) {  
                dist[nx][ny] = d + 1;  
                q[tt++] = {nx, ny};  
                if(tt==M) tt=0;
            } 
        }  
    }  
}  
  
int main() {  
    scanf("%d%d", &n, &m);  
    for (int i = 0; i < n; ++i) {  
        scanf("%s", g[i]);  
        for (int j = 0; j < m; ++j) {  
            if (g[i][j] == 'N') { sx = i; sy = j; }  
            if (g[i][j] == 'C') { tx = i; ty = j; }  
        }  
    }  
    int bestNtoE = INF, bestCtoE = INF;
    bfs_from(sx, sy, distN, bestNtoE);  
    bfs_from(tx, ty, distC, bestCtoE);  
    int ans = INF;  
    if (distN[tx][ty] != -1) ans = min(ans, distN[tx][ty]);   
    if (bestNtoE != INF && bestCtoE != INF) ans = min(ans, bestNtoE + bestCtoE);    
    if (ans == INF) puts("Bad Eureka");  
    else printf("%d\n", ans);  
    return 0;  
}  
/*  
6 6  
...E..  
EMM.M.  
.M..M.  
.MC.M.  
.MMM..  
N..E..  
*/  