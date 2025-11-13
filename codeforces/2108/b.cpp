#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, x;
    cin >> n >> x;
    if(x==0){
        if(n==1) cout << "-1\n";
        else if(n%2==0) cout << n << "\n";
        else cout << n+3 << "\n";
        return;
    }
    if(x==1){
        if(n==1) cout << "1\n";
        else if(n%2) cout << n << "\n";
        else cout << n+3 << "\n";
        return;
    }
    int cnt = __builtin_popcount(x);
    if(cnt >= n){
        cout << x << "\n";
        return;
    }
    cout << x + n - cnt + (n-cnt)%2 << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}