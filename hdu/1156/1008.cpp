#include<iostream>
using namespace std;
void solve(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    long long ans = 1;
    ans = ans * a * b * c * (d*e + d*max(d-1, 0)/2);
    cout << ans << '\n'; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}