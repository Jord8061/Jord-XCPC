#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(const string& s, const string& t, const vector<vector<int>>& pos) {
    int currentIndex = -1;
    for (char c : t) {
        int charIndex = c - 'a';
        if (pos[charIndex].empty()) return false;
        auto it = upper_bound(pos[charIndex].begin(), pos[charIndex].end(), currentIndex);
        if (it == pos[charIndex].end()) return false;
        currentIndex = *it;
    }
    return true;
}
int main() {
    int n, k, q;
    string s;
    cin >> n >> k >> s >> q;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    while (q--) {
        string t;
        cin >> t;
        if (isSubsequence(s, t, pos)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}