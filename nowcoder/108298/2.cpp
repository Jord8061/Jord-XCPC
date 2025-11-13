#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int n, q, tmp, cnt, p, v;
multiset<int> r;
map<int, int> l;
void solve(){
    l.clear();
    r.clear();
    cnt = 0;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        r.insert(a[i]);
    }
    for(int i=0; i<(n+1)/2; i++){
        l[*r.begin()]++;
        r.erase(r.begin());
    }
    if(l.rbegin()->first == *r.begin()){
        tmp = l.rbegin()->first;
        cnt = l[tmp];
        l.erase(tmp);
    }
    while(q--){
        cin >> p >> v;
        if(a[p] >= *r.begin()){
            r.erase(r.find(a[p]));
            if(tmp != *r.begin()){
                l[a[p]]++;
            }
            a[p] += v;
            r.insert(a[p]);
        }
        else{
            l[a[p]]--;
            if(l[a[p]] == 0) l.erase(a[p]);
            a[p] += v;
            if(a[p] >= *r.begin()){
                r.insert(a[p]);
                if(tmp == *r.begin()){
                    cnt += r.count(tmp);
                    r.erase(r.begin());
                }
            }
            else{
                l[a[p]]++;
            }
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