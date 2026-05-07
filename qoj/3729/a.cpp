#include<bits/stdc++.h>
//#define mod (long long)(1000000007)
#define mod (long long)(998244353)
#define ll long long
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define N 500005
#define INF 1e18
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpii vector<pair<int, int>>
#define vc vector<char>
#define vi vector<int>
#define is insert
#define mk make_pair
#define ce clear
#define pb push_back
#define ull unsigned long long
using namespace std;
int g[N], f[N], h[N];
int ans;
void get(vector<int> a){
    int n = a.size() - 1;
    vector<int> st;
    vector<vector<int>> s(n + 1, vector<int>(2, 0));
    st.push_back(1);
    for(int i=2; i<=n; i++){
        int tmp = 0, idx = -1;
        while(!st.empty() && a[st.back()] > a[i]){
            tmp = a[st.back()];
            idx = st.back();
            st.pop_back();
        }
        if(idx+1) s[i][0] = idx;
        if(!st.empty()) s[st.back()][1] = i;
        st.push_back(i);
    }
    for(int i=1; i<=n; i++){
        if(s[i][0])
            ans += a[s[i][0]] - a[i];
        if(s[i][1])
            ans += a[s[i][1]] - a[i];
    }
}
void solve(){
    int n, m = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m += a[i];
    }
    if(m % n){
        cout << "-1\n";
        return;
    }
    m /= n;
    for(int i = n; i >= 1; i--){
        if(a[i] > m){
            b[i - 1] = a[i] - m;
            a[i - 1] += a[i] - m;
            a[i] = m;
        }
        else if(a[i] < m){
            cout << "-1\n";
            return;
        }
    }
    vector<int> v_odd;
    vector<int> v_even;
    v_even.push_back(0);
    v_odd.push_back(0);
    for(int i = 1; i <= n; i += 2)
        v_odd.push_back(b[i]);
    for(int i = 2; i <= n; i += 2)
        v_even.push_back(b[i]);
    v_even.push_back(0);
    v_odd.push_back(0);
    ans = 0;
    get(v_even);
    get(v_odd);
    cout << ans << "\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
}