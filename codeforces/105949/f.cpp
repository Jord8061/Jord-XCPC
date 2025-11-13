#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int l=0, r = n-1, cnt1 = 0, cnt0 = 0;
    while(l <= r){
        while(cnt1 <= cnt0 && l <= r){
            if(s[l] != '0') cnt1++;
            l++;
        }
        while(cnt1 > cnt0 && l <= r){
            if(s[r] != '1') cnt0++;
            r--;
        }
    }
    ll ans = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1') cnt++;
        else if(s[i] == '?' && i<l) cnt++;
        else ans += cnt;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}