#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long ans=0;
    cin >> n;
    string s;
    cin >> s;
    vector<int> idx;
    for(int i=0; i<n; i++){
        if(s[i] == 'e') idx.push_back(i);
        else if(s[i] == 'f'){
            for(auto j : idx){
                ans += i - j;
            }
        }
    }
    cout << ans;
}