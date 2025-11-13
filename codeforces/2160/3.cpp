#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, a;
    cin >> n;
    vector<int> ans(2*n+2);
    vector<int> vis(2*n+2, 0);
    int r = 1;
    while(r < 2*n){
        r++;
        // cout << "? " << r ;
        vector<int> tmp;
        for(int i = 1; i <= r; i++)
            // if(!vis[i]) cout << " " << i;
            if(!vis[i]) tmp.push_back(i);
        cout << "? " << tmp.size();
        for(auto v: tmp) cout << " " << v;
        cout << "\n";
        cout.flush();
        cin >> a;
        if(a){
            ans[r] = a;
            vis[r] = 1;
        }
    }
    int l = 2*n-1;
    while(l > 0){
        while(vis[l]==1 && l > 1) l--;
        // cout << "? " << 2*n - l + 1;
        vector<int> tmp;
        for(int i = l; i <= 2*n; i++)
            // if(vis[i]!=-1) cout << " " << i;
            if(vis[i]!=-1) tmp.push_back(i);
        cout << "? " << tmp.size();
        for(auto v: tmp) cout << " " << v;
        cout << "\n";
        cout.flush();
        cin >> a;
        if(a){
            ans[l] = a;
            vis[l] = -1;
        }
        l--;
    }
    cout << "! ";
    for(int i = 1; i <= 2*n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    cout.flush();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}