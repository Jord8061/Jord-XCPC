#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int x = a + b + c;
        if(x%3){
            cout << "NO\n";
            continue;
        }
        x /= 3;
        if(b > x){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}