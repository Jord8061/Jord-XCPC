#include<bits/stdc++.h>
using namespace std;
void solve(){
    int m;
    scanf("%d", &m);
    while(m--){
        int hh, mm, t;
        char c;
        scanf("%d:%d %c%d", &hh, &mm, &c, &t);
        if(c=='+'){
            hh = (hh + t) % 24;
        }
        else{
            hh = (hh - t + 24) % 24;
        }
        printf("%02d:%02d\n", hh, mm);
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}