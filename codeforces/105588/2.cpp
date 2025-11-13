#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);
void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> ang(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ang[i] = atan2(y, x);
    }
    if (n == k) {
        cout << fixed << setprecision(10) << 2 * PI << '\n';
        return;
    }
    sort(ang.begin(), ang.end());
    ang.resize(2 * n);
    for (int i = 0; i < n; ++i) 
        ang[n + i] = ang[i] + 2 * PI;
    int m = n - k;
    double tmp = 1e100;
    for (int i = 0; i < n; ++i) 
        tmp = min(tmp, ang[i + m] - ang[i]);
    double ans = 2 * PI - tmp;
    cout << fixed << setprecision(10) << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
