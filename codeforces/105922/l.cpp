#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
typedef long long ll;
ll ksm(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    if(n&1 && m&1){
        cout << ksm(2, n+m-2) << "\n";
    }
    else if(n&1){
        cout << ksm(2, m-1) << "\n";
    }
    else if(m&1){
        cout << ksm(2, n-1) << "\n";
    }
    else{
        cout << "1\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}