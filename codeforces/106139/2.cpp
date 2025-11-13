#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld PI = 3.14159265358979323846;
const ld eps = 1E-8;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ld a, b, k, C;
    cin >> a >> b >> k >> C;
    ld t = fabsl(C) / sqrtl(k * k * a * a +  b * b);
    ld theta = acos(t);
    ld s = t*sqrtl(1-t*t)*a*b;
    ld ans = (PI - theta) * a * b;
    cout << fixed <<setprecision(8) << ans+s;
}