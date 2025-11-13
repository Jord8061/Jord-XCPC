#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
map<int, set<int>> edges;
int a[N];

void solve() {
    edges.clear();
    memset(a, 0, sizeof(a));
    int n, cnt = 0, sum = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }
    if (n == 2) {
        cout << "0\n";
        return;
    }
    for (auto [u, vs]: edges) {
        if (vs.size() == 1) {
            a[*vs.begin()]++;
            sum++;
            if (a[*vs.begin()] > cnt) {
                cnt = a[*vs.begin()];
            }
        }
    }
    cout << sum - cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}