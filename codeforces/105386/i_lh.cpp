#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    if(s.size()==1){
        cout<<"0\n";
        return;
    }
    int n=s.size();
    s="$"+s;
    int l = 1,r = n;
    while(s[l]==s[n]) l++;
    while(s[r]==s[1]) r--;
   // cout<<l<<" "<<r<<endl;
    int ss=-1,tt=-1;
    if(l==n){
        cout<<n/2<<"\n";
        return;
    }
    if(l==1&&r==n){
        ss=2;
        tt=n;
    }else{
        ss=l;
        tt=l+n-1;
    }
    for(int i=1;i<=l;++i){
        s+=s[1];
    }
   // cout<<l<<" "<<r<<endl;
 //  cout<<ss<<" "<<tt<<endl;
    vector<int> cnt;
    int ans = 0,now = 1;
    for(int i=ss;i<=tt;++i){
        if(i==l+n-1){
            if(s[i]==s[i-1]){
                now++;
            }
            cnt.push_back(now);
            now=1;
            break;        
        }
        if(s[i]==s[i-1]){
            now++;
        }else{
            cnt.push_back(now);
            now=1;
        }
    }
    int f=0;
    for(auto i:cnt){
       // cout<<i<<" ";
        if(i%2==0) f=1;
    }
    for(auto i:cnt){
        ans += i/2;
    }
    if(f) ans--;
    cout<<ans<<'\n';

    
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}