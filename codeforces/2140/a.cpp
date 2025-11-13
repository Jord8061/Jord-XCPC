#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, cnt0=0, cnt1=0;
    string ss;
    cin >> n >> ss;
    for(int i=0; i<n; i++){
        if(ss[i] == '0') cnt0++;
    }
    for(int i=0; i<cnt0; i++){
        if(ss[i] == '1') cnt1++;
    }
    cout << cnt1 << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}