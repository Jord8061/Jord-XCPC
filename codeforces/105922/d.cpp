#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll x, y;
    cin >> x >> y;
    for(int i=1; i<=min(y-x, 700LL); i++){
        if(__gcd(x, x+i) == 1 && __gcd(x+i, y) == 1){
            cout << x+i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}