#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
using ld = long double;

void solve(){
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1){
        cout << "1\n1 1 1\n";
        return;
    }
    if (n == m && n > 2){
        cout << n - 1 << endl;
        for (int i = 1; i <= n - 3; ++i){
            cout << "1 " << i << " " << i << endl;
        }
        cout << "1 " << n - 1 << " " << n - 1 << endl;
        cout << "2 " << n - 1 << " " << n - 1 << endl;
        return;



    }
    if (n < m){
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            cout << "1 ";
            cout << i << " 1\n"; 
        }
    }else{
        cout << m << endl;
        for (int i = 1; i <= m; ++i){
            cout << "1 ";
            cout << "1 " << i << endl;
        }        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}