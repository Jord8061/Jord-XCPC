#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> m >> n;
    int a[n+1], b[n+1], dp[m+1]={0};
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    for(int i=0; i<n; i++){
        for(int j=a[i]; j<=m; j++){
            dp[j] = max(dp[j], dp[j-a[i]]+b[i]);
        }
    }
    cout << dp[m];
}