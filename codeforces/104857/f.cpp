#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int> mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        mp[s]++;
        if(mp[s] > n/2) {
            cout << s << "\n";
            return 0;
        }
    }
    cout << "uh-oh\n";
    return 0;
}