#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int a, b, c;
    bool operator < (const item &x) const {
        return c*x.b > x.c*b;
    }
};
int w(item i, int t){
    return i.a - i.b*t;
}
signed main(){
    int T, n, ans=0;
    cin >> T >> n;
    item it[n+1];
    for(int i=0; i<n; i++) cin >> it[i].a;
    for(int i=0; i<n; i++) cin >> it[i].b;
    for(int i=0; i<n; i++) cin >> it[i].c;
    sort(it, it+n);
    int dp[T+1]={0};
    for(int i=0; i<n; i++){
        for(int j=T; j>=it[i].c; j--){
            dp[j] = max(dp[j], dp[j-it[i].c]+w(it[i], j));
            ans = max(ans, dp[j]);
        }
    }
    cout << ans;
}