#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a[n+1];
    for(int i=0; i<=n; i++) a[i].resize(k+1, 0);
    for(int i=1; i<=n; i++){
        ll tmp = a[i-1][0];
        for(int j=1; j<=k; j++){
            cin >> a[i][j];
            tmp = max(tmp, a[i-1][j]);
            a[i][j] += tmp;
        }
    }
    cout << a[n][k] << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}