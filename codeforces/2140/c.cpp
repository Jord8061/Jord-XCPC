#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];
void solve(){
    int n;
    cin >> n;
    if(n==1){
        cin >> n;
        cout << n << "\n";
        return;
    }
    cin >> a[1] >> a[2];
    int odd = a[1]*2+1, even = a[2]*2-2;
    int tmp = max((n-1)/2*2, a[2]*2+2-odd);
    ll ans = a[1]-a[2];
    for(int i=3; i<=n; i++){
        cin >> a[i];
        if(i&1)
            ans += a[i],
            odd = min(odd, a[i]*2+i),
            tmp = max(tmp, even - a[i]*2+i);
        else
            ans -= a[i],
            even = max(even, a[i]*2-i),
            tmp = max(tmp, a[i]*2+i - odd);
    }
    cout << ans+tmp << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}