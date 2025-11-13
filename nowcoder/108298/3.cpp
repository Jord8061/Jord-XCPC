#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            a[i].push_back(y);
        }
    }
}