#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
multiset<int> lSet, rSet;
multiset<pair<int, int>> lrPair;
void solve(){
    lSet.clear();
    rSet.clear();
    int n, l, r;
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        ans += r - l;
        lSet.insert(l);
        rSet.insert(r);
        lrPair.insert({l, r});
    }
    while(lSet.size()>1){
        int a = *lSet.begin();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}