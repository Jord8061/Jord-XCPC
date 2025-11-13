#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<int, set<int>> mp;
    int n, m, k, a, j=-1;
    cin >> n >> m >> k;
    for(int i=0; i<n*m; i++){
        int a;
        cin >> a;
        a /= k;
        if(j==-1) mp[a].insert(i);
        if(mp[a].size() == m) j=a;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}