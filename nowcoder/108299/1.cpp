#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
using ld = long double;
const int mod = 998244353;
const int N = 5E5+10;
ll dp[N][2];
ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+10), pre(n+10, 0);
    for(int i=1;i<=n;++i){
        cin >> a[i];
        pre[i] = pre[i-1] + (int)(a[i] == -1);
    }
    if(a[1]==1){
        dp[1][1] = 1;
    }
    else if(a[1]==0){
        dp[1][0] = 0;
    }
    else{
        dp[1][1] = 1;       
        dp[1][0] = 0; 
    }
    for(int i=2;i<=n;++i){
        if(a[i]==1){
            if(a[i-1]==1){
                dp[i][1] = dp[i - 1][1];
            }
            else if(a[i-1]==0){
                dp[i][1] = (dp[i - 1][0] + ksm(2, pre[i - 1]))%mod;
            }
            else{
                dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] + ksm(2, pre[i - 1]))%mod;
            }
        }
        else if(a[i]==0){
            if(a[i-1]==1){
                dp[i][0] = dp[i - 1][1];
            }
            else if(a[i-1]==0){
                dp[i][0] = dp[i - 1][0];
            }
            else{
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][0])%mod;
            }
        }
        else{
            if(a[i-1]==1){
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = dp[i - 1][1];
            }
            else if(a[i-1]==0){
                dp[i][1] = (dp[i - 1][0] + ksm(2, pre[i - 1]))%mod;
                dp[i][0] = dp[i - 1][0];
            }
            else{
                dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] + ksm(2, pre[i - 1]))%mod;
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][0])%mod;
            }
        }
    }
    for(int i=1;i<=n;++i){
        // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    ll ans = (dp[n][0] + dp[n][1])%mod;
    cout<<ans<<endl;
    for(int i=1;i<=n;++i){
        dp[i][0]=dp[i][1] = 0;
    }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}