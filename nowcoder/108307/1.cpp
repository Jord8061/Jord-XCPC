#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (__gcd(n, m) != 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> a(n), b(m);
    int now = 1;
    a[0] = 1,b[0]= 1;
    for(int i=1;i<=n;++i){
        if(i%2==0) a[now++] = i;
    }
    for(int i=n;i>1;--i){
        if(i&1) a[now++] = i;
    }    
    now = 1;
    for(int i=1;i<=m;++i){
        if(i%2==0) b[now++] = i;
    }
    for(int i=m;i>1;--i){
        if(i&1) b[now++] = i;
    }
    for(int i=0; i<n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    int dis = (m + 1) / 2;
    int d = abs(n - m);
    vector<vector<int>> p(n, vector<int>(m));
    for(int i=0;i<m;++i) p[0][i] = b[i];
    int lst = 0;
    for(int i = 1; i < n; ++i){
        int h = a[i] - 1; // 行
        
        for(int j=0; j<m; j++){
            p[h][(j+dis)%m] = p[lst][j] + m;
        }
        lst = h;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
} 