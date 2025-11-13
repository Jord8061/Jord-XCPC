#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int t, n, m;
    cin >> t >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll tmp = 0;
    for (int i = 0; i < m; i++) tmp += a[i];
    if (tmp > t) {
        cout << -1 << "\n";
        return;
    }
    cout << (t-tmp) / 40 << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}