#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (a[n] != b[n]) {
        cout << "NO\n";
        return;
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i] != b[i]) {
            ll tmp1 = a[i] ^ a[i+1];
            ll tmp2 = a[i] ^ b[i+1];
            if (tmp1 != b[i] && tmp2 != b[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}