#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<int, int> mp1, mp2;
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x %= k;
        x = min(x, k - x);
        mp1[x]++;
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x %= k;
        x = min(x, k - x);
        mp2[x]++;
    }
    for(auto [i, v] : mp1){
        if(mp1[i] != mp2[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}