#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, j=1;
    cin >> n;
    int a[n];
    cin >> a[0];
    int gcd = a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        gcd = __gcd(gcd, a[i]);
    }
    for(int i=0; i<n; i++){
        if(j && a[i] != gcd){
            a[i] = 2;
            j = 0;
        }
        else a[i] = 1;
    }
    if(j) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}