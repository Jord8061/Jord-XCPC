#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    }
    vector<vector<int>> minL(k + 1, vector<int>(n + 1, m + 2));
    for (int c = 1; c <= k; c++) minL[c][0] = m + 2;
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= k; c++) minL[c][i] = minL[c][i - 1];
        unordered_map<int, int> Pos;
        for (int j = 1; j <= m; j++) {
            int c = grid[i][j];
            if (!Pos.count(c)) Pos[c] = j;
        }
        for (auto& [c, j] : Pos) minL[c][i] = min(minL[c][i], j);
    }
    int res = 0;
    for (int x = 1; x <= n; x++) {
        int maxL = 0;
        bool f = true;
        for (int c = 1; c <= k; c++) {
            if (minL[c][x] == m + 2) {
                f = false;
                break;
            }
            maxL = max(maxL, minL[c][x]);
        }
        if (f && maxL <= m) res += m - maxL + 1;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}