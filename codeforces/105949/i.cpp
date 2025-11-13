#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int trie[N][26];
int cnt = 0;
void insert(string s){
    int node = 0;
    for(char c: s){
        int i = c - 'a';
        if(!trie[node][i]){
            trie[node][i] = ++cnt;
        }
        node = trie[node][i];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        insert(s);
    }
    cout << cnt;
    return 0;
}