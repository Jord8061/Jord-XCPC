#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int ans[N]; 
void solve(){
    int n, k, cnt=0;
    string ss;
    cin >> n >> k >> ss;
    int l=1, r=n;
    for(int i=0; i<n; i++){
        if(ss[i]=='1'){
            cnt++;
            ans[i] = l++;
        }
        else{
            cnt = 0;
            ans[i] = r--;
        }
        if(cnt == k){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}