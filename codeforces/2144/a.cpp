#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
void solve() {
    int n, a;
    cin >> n;
    ll sum[5] = {0};
    vector<int> ans[4];
    set<int> diff;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        for(int k = 0; k < 5; k++) {
            sum[k] += a;
        }
        if(!diff.count(sum[3] % 3) && diff.size() < 2){
            diff.insert(sum[3] % 3);
            ans[3].push_back(i);
            sum[3] = 0;
        }
        for(int k = 0; k < 3; k++) {
            if(sum[k] % 3 == k && ans[k].size() < 2){
                ans[k].push_back(i);
                sum[k] = 0;
            }
        }
    }
    if(sum[4] % 3) {
        cout << "0 0\n";
        return;
    }
    for(int k = 0; k < 4; k++) {
        if(ans[k].size() == 2 && ans[k][1] != n) {
            cout << ans[k][0] << ' ' << ans[k][1] << '\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}