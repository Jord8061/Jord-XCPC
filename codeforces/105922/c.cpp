#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    string op;
    cin >> op;
    long long ans = 0;
    if(op.back() == 's'){
        for(int i=0; i<n; i++) ans = (ans + a[i]) % Mod;
    }
    else{
        ans = 1;
        for(int i=0; i<n; i++) ans = (ans * a[i]) % Mod;
    }
    op.pop_back();
    while(!op.empty()){
        char c = op.back();
        op.pop_back();
        if(c == 's')ans = ans*n % Mod;
        else {}
    }
    cout << ans;
}