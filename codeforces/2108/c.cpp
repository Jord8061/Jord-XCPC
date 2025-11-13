#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
void solve(){
    int n, flag=-1, cnt=0;
    cin >> n >> a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i] > a[i-1]) flag = 1;
        else if(a[i] < a[i-1]){
            if(flag) cnt++; 
            flag = 0;
        }
    }
    if(flag) cnt++;
    cout << cnt << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}