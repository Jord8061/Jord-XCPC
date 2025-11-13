#include<iostream>
#include<set>
using namespace std;
const int N = 1e6+5;
int p[N], q[N];
set<int> st, nm;
int main(){
    int t, n;
    for(int i=0; i<N; i++) st.insert(i);
    for(int i=0; i<N; i++){
        for(auto x:st){
            if(t^x){
                t ^= x;
                p[i] = x;
                st.erase(x);
                nm.insert(x);
                if(*nm.begin()==0 && *nm.rbegin()==nm.size()-1) q[nm.size()]=1;
                break;
            }
        }
    }cin >> t;
    while(t--){
        cin >> n;
        if(q[n]){
            cout << p[0];
            for(int i=1; i<n; i++) cout << " " << p[i];
            cout << "\n";
        }else cout << "impossible\n";
    }return 0;
}