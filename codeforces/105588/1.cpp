#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    cout << "Yes\n";
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0; i<m; i++) a[i] = i+1;
    if(m & 1) {
        int j = 0;
        for(int i=0; i<n; i++) {
            for(int k=0; k<m; k++) {
                cout << a[(j+k)%m] + i*m << " ";
            }
            cout << "\n";
            j = (j+1)%m;
        }
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << a[j] + i*m << " ";
            }
            cout << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}