#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, a;
    string ss, tt;
    cin >> n >> q >> ss;
    while(q--){
        int ans=0, cnt=0;
        cin >> tt >> a;
        for(int i=0; i<min(ss.size(), tt.size()+a-1); i++){
            if(ss[i] != tt[i + a - 1]){
                ans += cnt*(cnt + 1) / 2;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        ans += cnt*(cnt + 1) / 2;
        cout << ans << "\n";
    }
}