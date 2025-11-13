#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int a[N];
vector<int> factors[N];
void init() {
    for (int i = 1; i < N ; i++) {
            for (int j = i; j < N; j += i) {
                factors[j].push_back(i);
            }
    }
}
int st[N];
void solve() {
    int n;
    cin >> n;
    //vector<int> a(n+1);
    int ma = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
       // cnt[a[i]]++;
    }
    sort(a+1,a+1+n);
    ll ans = 0;
    st[a[n]] = 1;

    for (int i = n-1; i >=1; i--) {
        for(auto j:factors[a[i]]){
            if(j+a[i]<=ma)
            ans += st[j+a[i]];
        }
        st[a[i]]++;
    }
    cout << ans << "\n";
    for(int i=0;i<=n;++i){
        st[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) solve();
}