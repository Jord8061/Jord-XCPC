#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
void solve(){
    ll n, k, m, ans=0;
    cin >> n >> k;
    map<ll, ll> mp;
    for(int i = 0; i<n; i++){
        cin >> m;
        ans += m/k;
        if(m%k) mp[k-m%k]++;
    }cin >> m;
    for(auto p: mp){
        while(p.first<=m && p.second){
            m -= p.first;
            p.second--;
            ans++;
        }
    }cout << ans+m/k << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}