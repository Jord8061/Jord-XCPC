#include<iostream>
#include<vector>
using namespace std;
void solve(){
    string ss;
    cin >> ss;
    int n=ss.size(), cnt=1, ans=0, j=0;
    vector<int> v;
    for(int i=1; i<n; i++){
        if(ss[i] == ss[i-1]) cnt++;
        else{
            v.push_back(cnt);
            cnt = 1;
        }
    }if(ss[0]==ss[n-1] && !v.empty()) v[0] += cnt;
    else v.push_back(cnt);
    cnt = 0;
    for(auto x:v){
        cnt += x/2;
        if(x%2==0) j=1;
    }if(v.size()==1) j=0;
    cout << cnt-j << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}