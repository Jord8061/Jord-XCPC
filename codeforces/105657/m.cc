#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int N=1e5+10;
template<class T>
inline void read(T &x)
{
    x=0;int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();};
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(f)x=~x+1;
}
template<class T,class ...T1>
inline void read(T &x,T1 &...x1)
{
    read(x),read(x1...);
}
int T,n,k;
int a[N];
int top,sta[N],l[N],r[N];
int gcd(int a,int b)
{
    if(a>b)swap(a,b);
    if(!a)return b;
    return gcd(b%a,a);
}
bool dfs(int x,int d)
{
    if(l[x])
    {
        if((a[l[x]]+d)%(a[x]+d))return 0;
        if(!dfs(l[x],d))return 0;
    }
    if(r[x])
    {
        if((a[r[x]]+d)%(a[x]+d))return 0;
        if(!dfs(r[x],d))return 0;
    }
    return 1;
}
void init()
{
    for(int i=1;i<=n;i++)l[i]=r[i]=a[i]=sta[i]=0;
}
void solve()
{
    read(n,k);
    for(int i=1;i<=n;i++)read(a[i]);
    if(n==1)
    {
        printf("%d %lld\n",k,1ll*k*(k+1)/2);
        return init();
    }
    top=0;
    for(int i=1,p;i<=n;i++)
    {
        p=top;
        while(p&&a[sta[p]]>a[i])p--;
        if(p)r[sta[p]]=i;
        if(p<top)l[i]=sta[p+1];
        sta[++p]=i;
        top=p;
    }
    int g=0;
    for(int i=1;i<n;i++)g=gcd(g,abs(a[i]-a[i+1]));
    if(g==0)
    {
        printf("%d %lld\n",k,1ll*k*(k+1)/2);
        return init();
    }
    vector<int>s;
    for(int i=1;i*i<=g&&i<=a[sta[1]]+k;i++)
        if(g%i==0)
        {
            s.push_back(i);
            if(g%i!=i&&g/i<=k)s.push_back(g/i);
        }
    int cnt=0;
    ll res=0;
    for(auto d:s)
    {
        if(d<=a[sta[1]])continue;
        if(dfs(sta[1],d-a[sta[1]]))cnt++,res+=d-a[sta[1]];
    }
    printf("%d %lld\n",cnt,res);
    init();
}
int main()
{
    // freopen("M.in","r",stdin);
    read(T);
    while(T--)solve();
    return 0;
}