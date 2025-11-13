#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n;
        a = n/2;
        b = n - a;
        cout << a*b+1 << "\n";
    }
}