#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int ans[N];
map<int, queue<int>> idxQueue;
void solve(){
    idxQueue.clear();
    ans[0] = 0;
    int n, a;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a;
        idxQueue[a].push(i);
        int beginIdx = 0;
        if(idxQueue[a].size() == a){
            beginIdx = idxQueue[a].front();
            idxQueue[a].pop();
        }
        ans[i] = ans[i-1];
        if(beginIdx) ans[i] = max(
            ans[beginIdx-1] + a, ans[i-1]
        );
    }
    cout << ans[n] << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}