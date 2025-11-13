#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(s[0]!='-'){
        int f = 0;
        for(int i = 0;i<n;++i){
            if(f==0&&s[i]=='0'){
                f++;
                cout << "10";
            }else{
                cout<<s[i];
            }
        }
        if(!f)  cout<<"1";
        cout << "\n";
    }
    else{
        int f = -1;
        for(int i = n-1;i>=0;--i){
            if(s[i]=='0'){
                f = i;
                break;
            }
        }
        if(f==-1){
            cout<<"-1";
            for(int i=1;i<n;++i){
                cout<<s[i];
            }
            cout<<"\n";
        }else{
            if(s[1] == '1'){
                for(int i=0; i<n; ++i){
                    if(s[i] == '0'){
                        for(int j=i; j<n; ++j){
                            if(s[j] == '0'){
                                f = j;
                            }
                            else{
                                i = n;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i=0;i<n;++i){
                if(i==f) cout <<"01";
                cout<<s[i];
            }
            cout<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}