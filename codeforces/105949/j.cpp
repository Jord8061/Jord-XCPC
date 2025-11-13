#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int tree[N] = {-1};
int l[4][N], r[4][N];
void solve(){
    int n, x, y;
    string s;
    ll ans = 0;
    cin >> n >> s;
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            l[i][j] = 0;
            r[i][j] = 0;
        }
    }
    for(int i=1; i<n; i++){
        cin >> x >> y;
        tree[y-1] = x-1;
    }
    for(int i=0; i<n; i++){
        int u = tree[i];
        if(s[i] == 'S' && u != -1){
            l[0][u]++;
            int v = tree[u];
            if(s[u] == 'C' && v != -1){
                l[1][v]++;
                int x = tree[v];
                if(s[v] == 'C' && x != -1){
                    l[2][x]++;
                    int y = tree[x];
                    if(s[x] == 'P' && y != -1){
                        l[3][y]++;
                        if(s[y] == 'C'){
                            // r[3][i]++;
                            ans++;
                        }
                    }
                }
            }
        }
        else if(s[i] == 'C' && u != -1){
            r[0][u]++;
            int v = tree[u];
            if(s[u] == 'P' && v != -1){
                r[1][v]++;
                int x = tree[v];
                if(s[v] == 'C' && x != -1){
                    r[2][x]++;
                    int y = tree[x];
                    if(s[x] == 'C' && y != -1){
                        r[3][y]++;
                        if(s[y] == 'S'){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        // if(s[i] == 'S') ans += r[3][i];
        // else 
        if(s[i] == 'C') ans += //l[3][i] + 
                                    (ll)l[1][i]*r[1][i] + 
                                    (ll)l[0][i]*r[2][i];
        else if(s[i] == 'P') ans += (ll)(r[0][i]-l[2][i])*l[2][i];
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}