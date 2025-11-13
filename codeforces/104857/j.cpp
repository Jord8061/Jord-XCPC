#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+5;
struct edge {
  int v, w;
};
struct node {
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
vector<edge> e[MAXN];
int dis[MAXN][2], vis[MAXN][2];
void dijkstra(int n, int s, int i) {
  priority_queue<node, vector<node>, greater<node>> q;
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  memset(vis, 0, (n + 1) * sizeof(int));
  dis[s][i] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u][i]) continue;
    vis[u][i] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v][i] > max(dis[u][i], w)) {
        dis[v][i] = max(dis[u][i], w);
        cout << "dis[" << v << "][" << i << "] updated to " << dis[v][i] << "\n";
        q.push({dis[v][i], v});
      }
    }
  }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dijkstra(n, 1, 0);
    dijkstra(n, n, 1);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    // 遍历每条边作为中转点，如果边权大于等于两端点的最大值，则更新答案
    for(int u=1; u<=n; u++){
        for(auto ed : e[u]){
            int v = ed.v, w = ed.w;
            if(w >= max(dis[u][0], dis[v][1])){
                ans = min(ans, 1LL * max(dis[u][0], dis[v][1])+w);
            }
        }
    }
    cout << ans << "\n";
}