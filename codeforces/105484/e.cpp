#include<iostream>
using namespace std;
void solve(){
    int n, k, cnt=0;
    cin >> n >> k;
    string s, t="nanjing";
    cin >> s;
    for(int i=0; i<min(k, 6); i++) s += s[i];
    for(int i=0; i<n; i++){
        if(s.substr(i, 7)==t) cnt++;
    }
    cout << cnt << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}