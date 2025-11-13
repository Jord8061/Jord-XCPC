#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll a[N];
ll tag[450], val[450];
bool dir[450];
ll n, q, v, siz, cnt;
unordered_map<ll, ll> mp;
mt19937_64 rd;
ll get_w(ll x){
    if(!mp.count(x)) mp[x] = rd();
    return mp[x];
}
void rebuild(int id){
    int l = id*siz, r = min(n, (id+1)*siz);
    val[id] = 0;
    for(int i=l; i<r; i++) val[id] ^= get_w(a[i] + tag[id]);
    dir[id] = 0;
}
void add(int l, int r){
    int st = l/siz, ed = r/siz;
    if(st == ed){
        for(int i=l; i<=r; i++) a[i] += v;
        rebuild(st);
        return;
    }
    for(int i=l; i<(st+1)*siz; i++){
        a[i] += v;
    }
    rebuild(st);
    for(int i=st+1; i<ed; i++){
        tag[i] += v;
        dir[i] = 1;
    }
    for(int i=ed*siz; i<=r; i++){
        a[i] += v;
    }
    rebuild(ed);
}
bool query(int l, int r){
    int st = l/siz, ed = r/siz;
    ll res = 0;
    if(st == ed){
        for(int i=l; i<=r; i++) res ^= get_w(a[i] + tag[st]);
        return res == 0;
    }
    for(int i=l; i<(st+1)*siz; i++) res ^= get_w(a[i] + tag[st]);
    for(int i=st+1; i<ed; i++){
        if(dir[i]) rebuild(i);
        res ^= val[i];
    }
    for(int i=ed*siz; i<=r; i++) res ^= get_w(a[i] + tag[ed]);
    return res == 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    siz = sqrt(n) + 1;
    cnt = (n + siz - 1) / siz;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<cnt; i++) val[i] = tag[i] = dir[i] = 0;
    for(int i=0; i<cnt; i++) rebuild(i);
    while(q--){
        int op, l, r;
        cin >> op >> l >> r;
        l--; r--;
        if(op == 0){
            cin >> v;
            add(l, r);
            continue;
        }
        if(query(l, r)) cout << "YES\n";
        else cout << "NO\n";
    }
}