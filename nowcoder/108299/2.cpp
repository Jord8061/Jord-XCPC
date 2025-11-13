#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long double pi = acos(-1);
const int N = 5e5 + 5;
ll a[N], b[N];
ll n, x, y;
bool judge(){
    for(int i = 0; i < n; i++){
        ll cross = (a[(i+1)%n]-a[i]) * (y-b[i]) - (b[(i+1)%n]-b[i]) * (x-a[i]);
        if(cross < 0) return false;
    }
    return true;
}
void solve(){
    vector<pair<ll, ll>> far, near;
    ll d_max = 0, d_min = LLONG_MAX;
    cin >> n >> x >> y;
    for(int i=0; i < n; ++i){
        cin >> a[i] >> b[i];
        ll d = (a[i]-x) * (a[i]-x) + (b[i]-y) * (b[i]-y);
        if(d > d_max){
            d_max = d;
            far.clear();
        }
        if(d == d_max) {
            far.push_back({a[i], b[i]});
        }
        if(d < d_min) {
            d_min = d;
            near.clear();
        }
        if(d == d_min) {
            near.push_back({a[i], b[i]});
        }
    }
    bool flag = judge();
    if(far.size() == 1){
        cout << pi * 2 << "\n";
        return;
    }
    ld angle = 0;
    int len1 = far.size(), len2 = near.size();
    if(!flag){
        cout << pi * 2 << "\n";
        return;
    }
    for(int i = 0; i < len1; ++i){
        ld new_angle = (
            atan2(far[(i+1)%len1].second - y, far[(i+1)%len1].first - x) - 
            atan2(far[i].second - y, far[i].first - x)
        );
        if(new_angle < 0) new_angle += 2 * pi;
        angle = max(angle, new_angle);
    }
    cout << fixed << setprecision(10) << angle << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}