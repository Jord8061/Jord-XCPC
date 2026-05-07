#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, ans = 0, idx = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++) b[i] = a[i+1] + a[i];
    for(int i = 0; i < n-2; i++){
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if((int)(it - a.begin()) - i > ans){
            ans = (int)(it - a.begin()) - i;
            idx = i;
        }
    }
    if(ans < 3) ans = 0;
    cout << ans;
    for(int i = 0; i < ans; i++) cout << " " << a[idx+i];
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}