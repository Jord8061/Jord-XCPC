#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<set<int>> v(6,{1,2,3,4,5,6});
    for(int i=0; i<6; i++){cin >> n; v[i].erase(n);}
    cin >> n;
    while(--n) for(int i=0; i<6; i++) v[i].erase(--v[i].end());
    for(int i=0; i<6; i++) cout << *v[i].rbegin() << (i<5 ? ' ' : '\n');
}