#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> a(n + 1, 0);
    int tmp = 1;
    ll p = 0;
    for (int i = 1; i <= n; i++) {
        ll d = b[i] - p; 
        p = b[i];
        ll prev = i - d;
        if (prev == 0) {
            a[i] = tmp++;
        } else {
            a[i] = a[prev];
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? '\n' : ' ');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
