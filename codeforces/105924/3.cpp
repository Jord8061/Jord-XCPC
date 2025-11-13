#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
map<int, set<int>> mp;
void solve(){
    mp.clear();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    mp[1].insert(a[1]);
    for(int i=2; i<=n; i++){
        int flag = 0;
        for(int j=mp.rbegin()->first; j>=1; j--){
            if(mp.count(j)){
                for(auto p: mp[j]){
                    if(a[i] % p == 0 || p % a[i] == 0){
                        mp[j+1].insert(a[i]);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(!flag) mp[1].insert(a[i]);
    }
    cout << mp.rbegin()->first << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}