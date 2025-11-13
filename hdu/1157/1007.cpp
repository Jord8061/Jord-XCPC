#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n1, n2, p, q;
    cin >> n1 >> n2;
    set<int> s1;
    int tmp = 0, cnt = 0;
    for(int i=0; i<n1; i++){
        s1.insert(tmp);
        cin >> p >> q;
        tmp += p*48/q;
    }
    tmp = 0;
    for(int i=0; i<n2; i++){
        if(s1.find(tmp) != s1.end()){
            cnt++;
        }
        cin >> p >> q;
        tmp += p*48/q;
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}