#include<bits/stdc++.h>
//#define mod (long long)(1000000007)
#define mod (long long)(998244353)
#define ll long long
#define int long long
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpii vector<pair<int, int>>
#define vc vector<char>
#define vs vector<string>
#define vi vector<int>
#define is insert
#define mk make_pairs
#define ce clear
#define pb push_back
#define ull unsigned long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define N 300005
#define M 505
#define INF 1e18
using namespace std;
int cnt;
void build(int n, int m){
    int r = n * m;
    rep(p, 0, (1ll << r) - 1){
        vvi mp(n, vi(m));
        rep(i, 0, n - 1){
            rep(j, 0, m - 1){
                int q = i * m + j;
                if((p >> q) & 1)
                    mp[i][j] = 1;
                else
                    mp[i][j] = 0;
            }
        }
        int ok = 1;
        rep(i, 0, n - 1){
            rep(j, 0, m - 1){
                int ret = 0;
                rep(k, 0, m - 1)
                    ret ^= mp[i][k];
                rep(k, 0, n - 1)
                    ret ^= mp[k][j];
                if(ret != mp[i][j]){
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            cout << "***************\n";
            cnt++;
            rep(i, 0, n - 1){
                rep(j, 0, m - 1)
                    cout << mp[i][j] << " ";
                cout << "\n";
            }
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    cnt = 0;
    build(n, m);
    cout << "&&&&&&&&&&&&&&\n";
    cout << cnt << "\n";
}
signed main(){
    // ios::sync_with_stdio(0);
    // cout.tie(0);
    // cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
}