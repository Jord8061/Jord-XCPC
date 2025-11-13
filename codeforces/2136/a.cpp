#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(a >= (max(b-2, 0)+1)/2 && c >= (max(d-2, 0)+1)/2) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}