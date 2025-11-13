#include <bits/stdc++.h>
using i64 = long long;

void SOL() {
  i64 n, k;
  std::cin >> n >> k;

  i64 res = 1;
  std::vector<i64> arr(2 * n + 1);
  std::vector G(2 * n + 1, std::vector<std::pair<int, int>>());
  for (int i = 1; i <= n; ++i) {
    std::cin >> arr[i];
    arr[i + n] = arr[i] + k;
  }

  for (int i = 0; i < n; ++i) {
    G[i].emplace_back(i + 1, 0);
    G[i + n].emplace_back(i + n + 1, 0);
    G[i].emplace_back(i + n + 1, 1);
    G[i + n].emplace_back(i + 1, 1);
  }

  auto dfs = [&](auto &&self, int u, int r, i64 ans) -> void {
    if (u == n || u == n + n) {
      res = std::max(res, ans);
      return;
    }
    if (u && ans < res) return;
    
    for (auto [v, w] : G[u]) {
      if (w == 0) self(self, v, r, std::gcd(ans, arr[v]));
      else if (r >= 1) self(self, v, r - 1, std::gcd(ans, arr[v]));
    }
  };

  dfs(dfs, 0, 2, 0);
  std::cout << res << '\n';
}

int main(void) {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

  int _T = 1;
  std::cin >> _T;

  while (_T--) SOL();
}