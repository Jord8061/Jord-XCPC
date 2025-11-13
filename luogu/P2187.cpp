#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int w[n+1], d[n+1], dp[m+1]={0};
    for(int i=0; i<n; i++) cin >> w[i] >> d[i];
    for(int i=0; i<n; i++){
        for(int j=m; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+d[i]);
        }
    }
    cout << dp[m];
}