#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
  int u, v, c;
  ll l;
  edge(int u, int v, int c, ll l):
    u(u), v(v), c(c), l(l) {}
};
const int maxn = 5e5+5;
vector<edge> Edges;
vector<int> G[maxn]{};

set<int> cities, tmp;
int vis[maxn];

void addEdge(int u, int v, int c, ll l){
    G[u].emplace_back(Edges.size());
    Edges.emplace_back(u, v, c, l);
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        G[i].clear();
        vis[i] = 0;
    }
    Edges.clear();
    cities.clear();
    cities.insert(1);
    vis[1] = 1;

    while(m--){
        int u, v, c, l;
        cin >> u >> v >> c >> l;
        addEdge(u, v, c, l);
        addEdge(v, u, c, l);
    }
    // bfs
    while(k--){
        int a, b;
        cin >> a >> b;
        int city = *cities.begin();
        cities.erase(cities.begin());
        for(auto i: G[city]){
            int u = Edges[i].u, v = Edges[i].v, c = Edges[i].c, l = Edges[i].l;
            if(c == a && l <= b) 
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}