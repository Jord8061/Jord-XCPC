#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int f[N];
int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) f[y] = x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    for(int i=1; i<=n; i++) f[i] = i;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if(find(x) == find(y)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}