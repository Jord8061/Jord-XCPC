#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<int, int> mp;
    int n, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        mp[a]++;
    }
    if(mp.count(-1)) mp.erase(-1);
    if(mp.count(0) || mp.size() > 1) cout << "NO\n";
    else cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}