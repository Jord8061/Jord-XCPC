#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5;
int a[N];
unordered_map<int, int> mp;
int main(){
    int k;
    cin >> k;
    for(int i=0; i<(1<<k); i+=2){
        cin >> a[i];
        a[i+1] = -1;
        mp.insert({a[i], i});
    }
    for(int j=k-2; j>=0; j++){
        for(int i=0; i<(1<<j); i++){
            int tmp;
            cin >> tmp;
            if(tmp < a[i<<j] && tmp < a[(i+1)<<j]){
                cout << "No Solution";
                return 0;
            }
            if(tmp >= a[i<<j] && tmp >= a[(i+1)<<j]){
                if(a[i*2] < a[(i+1)*2]){

                }
            }
        }
    }
}