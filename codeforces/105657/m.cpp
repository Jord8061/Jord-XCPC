#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
int a[N], s[N][2];
vector<int> ans;
int num = 0;
void dfs(int p){
    for(int i=0; i<2; i++){
        if(s[p][i]){
            vector<int> tmp;
            for(auto x: ans)
                if((a[s[p][i]] + x) % (a[p] + x) == 0) tmp.push_back(x);
            ans = tmp;
            if(ans.empty()) return;
            dfs(s[p][i]);
        }
    }
}
void solve(){
    memset(s, 0, sizeof s);
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<int> st;
    st.push_back(1);
    num = 0;
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
    for(int i=1; i<n; i++){
        if(num && a[i+1] - a[i]) num = __gcd(num, abs(a[i+1] - a[i]));
        else if(!num) num = abs(a[i+1] - a[i]);
    }
    if(num == 0){
        cout << k << ' ' << 1LL*(k+1)*k/2 << '\n';
        return;
    }
    ans.clear();
    for(int i=1; i*i<=num && i<=a[st[0]]+k; i++){
        if(num % i == 0){
            if(i-a[st[0]] > 0) ans.push_back(i-a[st[0]]);
            if(num/i-a[st[0]] > 0 && num/i-a[st[0]] <= k && i != num/i) ans.push_back(num/i-a[st[0]]);
        }
    }
    if(!ans.empty()) dfs(st[0]);
    cout << ans.size() << ' ' << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}