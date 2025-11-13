#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
typedef long long ll;
ll a[N]={0}, b[N]={0};
ll primes[N];
ll prefixSum[N];
void __init__(){
    const int LIMIT = 1e7;
    vector<bool> isPrime(LIMIT + 1, true);
    isPrime[0] = isPrime[1] = false;
    int count = 0;
    for (int i = 2; i <= LIMIT && count < N; i++) {
        if (isPrime[i]) {
            primes[count] = i;
            prefixSum[count] = (count == 0 ? i : prefixSum[count - 1] + i);
            count++;
            for (int j = 2 * i; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    b[n+1] = 0;
    int idx = 0;
    for(int i=n; i>0; i--){
        b[i] = a[i] + b[i+1];
        if(b[i] < prefixSum[idx]){
            cout << n-idx << "\n";
            return;
        }
        idx++;
    }
    cout << 0 << "\n";
}
int main(){
    __init__();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}