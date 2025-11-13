#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a.begin(), a.end());

}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}