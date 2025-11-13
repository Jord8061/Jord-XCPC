#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MOD = 10007;
void solve(){
    ll k, c, d, e, f, cnt = 0;
    cin >> k >> c >> d >> e >> f;
    for(ll i=1; i<MOD; i++){
        ll tmp = i*i*i*c + i*i*d + i*e + f;
        ll tmp2 = 0, pow = 1;
        while(tmp){
            ll x = tmp % 27;
            if(x==0) break;
            tmp /= 27;
            tmp2 += x * pow;
            tmp2 %= MOD;
            pow *= 10;
            pow %= MOD;
        }
        if(tmp2 == i) cnt++;
    }
    cout << cnt << "\n";
}
int main(){
    int T;
    cin >> T;
    while(T--) solve();
}