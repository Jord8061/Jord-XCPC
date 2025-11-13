#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        int dx = abs(X - x);
        int dy = abs(Y - y);
        int da = max(dx, dy);
        int di = min(dx, dy);
        if(da && da < 3 && !di) cout << "2\n";
        else cout << (da+1)/2 << "\n";
    }
}