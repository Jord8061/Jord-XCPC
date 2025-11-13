#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, vector<int>> mpx, mpy;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a;
            mpx[a].push_back(i);
            mpy[a].push_back(j);
        }
    }
    ll ans = 0;
    for(auto [x, y]: mpx){
        sort(y.begin(), y.end());
        for(int i=1; i<y.size(); i++){
            ans += 1ll * (y[i] - y[i-1]) * i * (y.size() - i);
        }
    }
    for(auto [x, y]: mpy){
        sort(y.begin(), y.end());
        for(int i=1; i<y.size(); i++){
            ans += 1ll * (y[i] - y[i-1]) * i * (y.size() - i);
        }
    }
    cout << ans*2 << "\n";
}