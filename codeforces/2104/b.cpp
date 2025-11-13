#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N]={0}, b[N]={0};
map<int, int> mp;
void solve(){
    mp.clear();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    b[n+1] = 0;
    for(int i=n; i>0; i--){
        b[i] = a[i] + b[i+1];
        if(mp[a[i]] > 1) mp[a[i]]--;
        else mp.erase(a[i]);
        ll tmp = 0;
        if(!mp.empty()){
            auto it = mp.rbegin();
            tmp = it->first + b[i+1];
        }
        cout << max(b[i], tmp) << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}