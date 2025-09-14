#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int N = 3e5+10;
const int M = 1e6+10;
struct Idiom {int a, b, c, d;} idm[N];
map<int, vector<int>> head_map;
int m, fir[4], End[4];
int dist[N],ans=-1;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> que;

int main() {
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &idm[i].a, &idm[i].b, &idm[i].c, &idm[i].d);
        head_map[idm[i].a].push_back(i);
    }
    for (int i = 0; i < 4; ++i) scanf("%d", &fir[i]);
    for (int i = 0; i < 4; ++i) scanf("%d", &End[i]);
    
    for (int idx : head_map[fir[0]]) {
        if (idm[idx].a == fir[0] && idm[idx].b == fir[1] && idm[idx].c == fir[2] && idm[idx].d == fir[3]) {
            dist[idx] = 1;
            que.push({1, idx});
        }
    }
    while (!que.empty()) {
        int d = que.top().first, id = que.top().second; 
        que.pop();
        if (d > dist[id]) continue;
        // printf("%d %d\n",d,id);
        // printf("%d %d %d %d\n",idm[id].a,idm[id].b,idm[id].c,idm[id].d);
        // printf("%d %d %d %d\n",End[0],End[1],End[2],End[3]);
        // printf("----\n");
        if (idm[id].a == End[0] && idm[id].b == End[1] && idm[id].c == End[2] && idm[id].d == End[3]) {
            ans = ans==-1?d:min(ans, d);
            continue;
        }
        for (int nxt : head_map[idm[id].d]) {
            if (dist[nxt] > d + 1) {
                dist[nxt] = d + 1;
                que.push({dist[nxt], nxt});
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}