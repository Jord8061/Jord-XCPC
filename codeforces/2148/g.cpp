#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int cnt[N];
void solve(){
    memset(cnt, 0, sizeof(cnt));
    unordered_set<int> vis;
    int n, a, m = 0;
    cin >> n;
    for(int _=0; _<n; _++){
        cin >> a;
        for(int i=1; i<=450; i++){
            if(a%i == 0){
                cnt[i]++;
            }
            else vis.insert(i);
        }
        int ans = 0;
        for(auto p: vis){
            ans = max(ans, cnt[p]);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}