#include<bits/stdc++.h>
using namespace std;
#define int long long
int getbit(int x, int i) {
    return (x >> i) & 1;
}
int getlen(int x) {
    int len = 0;
    while (x) {
        len++;
        x >>= 1;
    }
    return len;
}
void solve() {
    vector<int> ans;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "0\n";
        return;
    }
    if (a == b && a == 0 && c) {
        cout << "-1\n";
        return;
    }
    int x = getlen(a), y = getlen(b), z = getlen(c);
    if(x > y) {
        ans.push_back(4);
        b ^= a;
        y = x;
    }
    else if(x < y) {
        ans.push_back(3);
        a ^= b;
        x = y;
    }
    for(int i=1; i<=z-x; i++) {
        ans.push_back(1);
        a <<= 1;
        if(getbit(a, y-1) != getbit(c, z-i-1)) {
            ans.push_back(3);
            a ^= b;
        }
    }
    while(y--){
        if(getbit(a, y) != getbit(c, y)) {
            ans.push_back(3);
            a ^= b;
        }
        ans.push_back(2);
        b >>= 1;
    }
    ans.push_back(4);
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}