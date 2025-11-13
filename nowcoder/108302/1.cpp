#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int N = 5e5 + 5;

ll dp[2][N];   // 只保留两行，滚动数组优化
ll F[N];       // 存储每个 n 的答案：∑ i^3 ⋅ dp[i][n]

inline ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}

inline ll mod_mul(ll a, ll b) {
    return (a * b) % MOD;
}

inline ll cube(ll x) {
    return mod_mul(x, mod_mul(x, x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[0][0] = 1;  // dp[0][0] = 1

    for (int n = 1; n < N; ++n) {
        int cur = n % 2, prev = 1 - cur;
        dp[cur][0] = 0;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            dp[cur][i] = mod_add(mod_mul(n - 1, dp[prev][i]), dp[prev][i - 1]);
            sum = mod_add(sum, mod_mul(cube(i), dp[cur][i]));
        }
        F[n] = sum;
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << F[n] << '\n';
    }

    return 0;
}
