#include<bits/stdc++.h>
using namespace std;
int const N = 2e3 + 5;
int c[N][N];
set<int> s;
map<int, int> mp;
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c[i][j];
            if(i == 1) s.insert(c[i][j]);
        }
    }
    int ans = n*m - s.size();
    for(int i=1; i<=m; i++){
        int cnt = 0;
        for(int j=2; j<=n; j++){
            if(c[j][i] == c[1][i]) cnt++;
            else break;
        }
        mp[c[1][i]] = max(mp[c[1][i]], cnt);
    }
    for(auto [x, y]: mp){
        ans -= y;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while(t--) solve();
}