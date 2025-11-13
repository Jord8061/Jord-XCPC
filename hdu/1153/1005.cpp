#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
void solve(){
    int P, n, k;
    cin >> P >> n >> k;
    vector<int> v[2];
    for(int i=0; i<n; i++){
        int t, p;
        cin >> t >> p;
        v[t].push_back(p);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<int>());
    vector<int> sum = v[1];
    for(int i=1; i<v[1].size(); i++) sum[i] += sum[i-1];
    int a = v[0].size(), b = v[1].size();
    long double tmp=P, ans=P;
    for(int i=0; i<=min(k, a); i++){
        if(i > 0) tmp *= v[0][i - 1] * 0.1;
        int rem = k - i;
        long double dis = (rem>0 && rem<=b) ? sum[rem-1] : 0;
        ans = min(ans, tmp - dis);
    }
    cout << fixed << setprecision(2) << max(ans, 0.0L) << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}