#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class Info>
struct SGT {
    #define l(p) (p << 1)
    #define r(p) (p << 1 | 1)
    int n;
    std::vector<Info> info;
    SGT() {}
    SGT(int _n, Info _v = Info()) {
        init(_n, _v);
    }
    template<class T>
    SGT(std::vector<T> _init) {
        init(_init);
    }
    void init(int _n, Info _v = Info()) {
        init(std::vector(_n, _v));
    }
    template<class T>
    void init(std::vector<T> _init) {
        n = _init.size();
        info.assign(4 << std::__lg(n), Info());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = _init[l];
                return;
            }
            int m = l + r >> 1;
            self(self, l(p), l, m);
            self(self, r(p), m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) { // 这个就是 y 总的 pushup
        info[p] = info[l(p)] + info[r(p)];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        if (x < m) {
            modify(l(p), l, m, x, v);
        } else {
            modify(r(p), m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y or r <= x) {
            return Info();
        }
        if (l >= x and r <= y) {
            return info[p];
        }
        int m = l + r >> 1;
        return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    #undef l
    #undef r
};

struct Info {
    ll sum;
    Info(){
        sum=0;
    }
    Info(ll v){
        sum = v;
    }
};
Info operator+(Info a, Info b) {
    Info c;
    c.sum = gcd(a.sum, b.sum);
    return c;
}

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+10), pre(n+10), suf(n+10),c(n+10);
    vector<Info> b(n+10);

    for(int i=1;i<=n;++i){
        cin >> a[i];
        b[i].sum=a[i]+k;
        c[i]=a[i]+k;
    }
    if(n==1){
        cout<<a[1]+k<<"\n";
        return;
    }
    vector<int> lp;
    for(int i=1;i<=n;++i){
        pre[i]=gcd(pre[i-1], a[i]);
    }
    for(int i=n;i>=1;--i){
        suf[i]=gcd(suf[i+1], a[i]);
    }
    for(int i=1;i<=n;++i){
        if(pre[i]!=pre[i+1]||i==n){
            lp.push_back(i);
        }
    }
    SGT<Info> sgt(b);
    ll ans = 0;
    for(auto l:lp){
        if(l==n){
            ans=max(ans,pre[l]);
            break;
        }
        ll val1 = pre[l];
        ll pre = c[l+1];
        int L = l+1,R=n;
        while(true){
            while(L<R){
                int mid = L + R + 1 >> 1;
                ll val = sgt.query(l+1,mid+1).sum;
                if(val<pre){
                    R = mid-1;
                }else{
                    L = mid;
                }
            }
           // cout<<L<<" #";

            ll nowval = sgt.query(l+1, L+1).sum;
            // if(L==4){
            //     cout<<endl;
            //     cout<<val1<<" "<<nowval<<" "<<suf[L+1]<<endl;
            //    // cout<<nowval<<" ]\n";
            // }
            ll nowans = gcd(val1, nowval);
            nowans = gcd(nowans, suf[L+1]);
            ans=max(ans, nowans);
            // if(L==4){
            //     cout<<nowans<<" "<<ans<<" pp\n";
            // }
            if(L==n) break;
            pre = sgt.query(l+1, L+2).sum;
            L = L + 1;
            R = n;
        }
    //    cout<<endl;
    }
    cout<<ans<<"\n";

    
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