#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s=="AB") cout << "Alice\n";
    else if(s=="BA") cout << "Bob\n";
    else
    {
        if(s[0]=='A'&&s[n-1]=='A') cout << "Alice\n";
        else if(s[0]=='B'&&(s[n-1]=='B'||s[n-2]=='B')) cout << "Bob\n";
        else
        {
            if(s[0]=='A'&&s[n-1]=='B')
            {
                bool t=true;
                for(int i=1;i<n-1;i++)
                {
                    if(s[i]=='B')
                    {
                        cout << "Bob\n";
                        t=false;
                        break;
                    }
                }
                if(t) cout << "Alice\n";
            }
            else if(s[0]=='B'&&s[n-1]=='A')
            {
                bool t=true;
                for(int i=1;i<n-1;i++)
                {
                    if(s[i]=='A')
                    {
                        cout << "Alice\n";
                        t=false;
                        break;
                    }
                }
                if(t) cout << "Bob\n";
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}