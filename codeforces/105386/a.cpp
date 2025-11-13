#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
typedef long long ll;
int s[N];
struct contest{
    int s, v=0, cnt=0;
};
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> p(n, vector<int>(m, 0));
    contest C[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
        C[i].s = s[i];
        for(int j=0; j<m; j++){
            cin >> p[i][j];
            if(p[i][j] == -1) C[i].cnt++;
            else C[i].v += p[i][j];
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}