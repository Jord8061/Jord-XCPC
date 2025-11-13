#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    vector<int> mp(101, 0);
    int n, m=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    while(mp[m]) m++;
    cout << m << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}