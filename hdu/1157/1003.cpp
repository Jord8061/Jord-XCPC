#include<bits/stdc++.h>
using namespace std;
int mp[505][505];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void solve(){
    queue<pair<int, int>> q1, q2;
    int n, m, r, x;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            mp[i][j] = 1;
        }
        cin >> r;
        while(r--){
            cin >> x;
            mp[i][x] = 0;
        }
    }
    for(int i=1; i<=n; i++)
        if(mp[i][1] == 1){
            q1.push({i, 1});
            mp[i][1] = 0;
        }
    int step = 1, ans = 0;
    while(!q1.empty()){
        while(!q1.empty()){
            auto [x, y] = q1.front();
            if(y == m){
                cout << step << "\n";
                return;
            }
            q1.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 1){
                    mp[nx][ny] = 0;
                    q2.push({nx, ny});
                }
            }
        }
        swap(q1, q2);
        step++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}