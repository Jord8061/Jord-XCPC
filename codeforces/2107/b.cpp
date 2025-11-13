#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<int, int> mp;
    int n, k, a, sum=0;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a;
        sum += a;
        mp[a]++;
    }
    if(mp.rbegin()->first - mp.begin()->first > k+1){
        cout << "Jerry\n";
        return;
    }
    if(mp.rbegin()->first - mp.begin()->first == k+1 && mp.rbegin()->second > 1){
        cout << "Jerry\n";
        return;
    }
    if(sum%2){
        cout << "Tom\n";
        return;
    }
    cout << "Jerry\n";
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}