#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<ll> q1, q2;
void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    for(char c : s1) q1.push_back(c - '0');
    for(char c : s2) q2.push_back(c - '0');

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}