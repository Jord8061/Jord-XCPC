#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], s[N][2];
void solve(){
    memset(s, 0, sizeof(s));
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<int> st;
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
        cout << a[i] << ": ";
        if(s[i][0]) cout << "L->" << a[s[i][0]] << ' ';
        if(s[i][1]) cout << "R->" << a[s[i][1]] << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}