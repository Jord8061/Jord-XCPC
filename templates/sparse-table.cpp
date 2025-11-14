#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N], st[30][N];
int n;
void init(){
    for(int i=1; i<=n; i++) st[0][i] = a[i];
    for(int i=1; i<=(int)log2(n); i++){
        for(int j=1; j+(1<<i)-1<=n; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(int l, int r){
    int k = log2(r-l+1);
    return min(st[k][l], st[k][r-(1<<k)+1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    init();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}