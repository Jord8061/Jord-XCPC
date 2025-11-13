#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> edges;
vector<int> ans;
void solve(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(auto [x, y] : edges){
        if(y.size() % 2) ans.push_back(x);
    }
    cout << ans.size()/2 << "\n";
    for(int i=0; i<ans.size(); i+=2) cout << ans[i] << " " << ans[i+1] << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while(t--) solve();
}