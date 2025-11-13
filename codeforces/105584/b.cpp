#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        if(n == 0) return 0;
        int a[n], b[n];
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int sum_a = 0, sum_b = 0, cnt = 0, flag = 0;
        for(int i=0; i<n; i++){
            sum_a += a[i];
            sum_b += b[i];
            if(sum_a > sum_b){
                if(flag && flag != 1) cnt++;
                flag = 1;
            }
            if(sum_a < sum_b){
                if(flag && flag != -1) cnt++;
                flag = -1;
            }
        }
        cout << cnt << "\n";
    }
}