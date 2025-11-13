#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n&1){
        n -= 3;
        n /= 2;
        while(n--) cout << "-1 1 ";
        cout << "-1 3 -1\n";
    }
    else{
        n -= 2;
        n /= 2;
        while(n--) cout << "-1 1 ";
        cout << "-1 2\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}