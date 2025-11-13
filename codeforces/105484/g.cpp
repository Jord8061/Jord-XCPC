#include<iostream>
#include<cstdio>
#include<cmath>
using  namespace std;
const int N=2e5+10;
const double INF=1e30;
template<class T>
inline void read(T &x)
{
    x=0;int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(f)x=~x+1;
}
template<class T,class ...T1>
inline void read(T &x,T1 &...x1)
{
    read(x),read(x1...);
}
int T;
int n,rt;
int fa[N];
int son[N][2];
int nowtot;
int si[N],maxp[N];
bool vis[N];

void get_rt(int x,int fa)
{
    if(vis[x])return ;
    si[x]=1;
    maxp[x]=0;
    for(int i=0;i<2;i++)
    {
        int y=son[x][i];
        if(vis[y])continue;
        get_rt(y,x);
        si[x]+=si[y];
        maxp[x]=max(maxp[x],si[y]);
    }
    maxp[x]=max(maxp[x],nowtot-si[x]);
    if(maxp[x]<maxp[rt])rt=x;
}
void dfs(int x)
{
    if(nowtot==1)
    {
        printf("! %d\n",x);
        return ;
    }
    if(vis[x])return ;
    rt=0;
    get_rt(x,0);
    x=rt;
    vis[x]=1;
    int y;
    if(son[x][0]&&son[x][1])
    {
        printf("? %d %d\n",son[x][0],son[x][1]);
        fflush(stdout);
        int ne;
        read(ne);
        if(ne==son[x][0])y=son[x][0];
        else if(ne==son[x][1])y=son[x][1];
        else y=fa[x];
        nowtot=si[y];
        dfs(y);
    }
    else if(son[x][0])
    {
        if(fa[x])
        {
            printf("? %d %d\n",son[x][0],fa[x]);
            fflush(stdout);
            int ne;
            read(ne);
            if(ne==son[x][0])y=son[x][0];
            else y=fa[x];
            nowtot=si[y];
            dfs(y);
        }
        else
        {
            printf("? %d %d\n",son[x][0],x);
            fflush(stdout);
            int ne;
            read(ne);
            printf("! %d\n",ne);
            return ;
        }
    }
    else if(son[x][1])
    {
        if(fa[x])
        {
            printf("? %d %d\n",son[x][1],fa[x]);
            fflush(stdout);
            int ne;
            read(ne);
            if(ne==son[x][1])y=son[x][1];
            else y=fa[x];
            nowtot=si[y];
            dfs(y);
        }
        else
        {
            printf("? %d %d\n",son[x][1],x);
            fflush(stdout);
            int ne;
            read(ne);
            printf("! %d\n",ne);
            return ;
        }
    }
    else
    {
        printf("? %d %d\n",fa[x],x);
        fflush(stdout);
        int ne;
        read(ne);
        printf("! %d\n",ne);
        return ;
    }
}
void solve()
{
    read(n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            read(son[i][j]);
            if(son[i][j])fa[son[i][j]]=i;
        }
    nowtot=n;
    maxp[0]=n;
    dfs(1);
    for(int i=1;i<=n;i++)fa[i]=0,vis[i]=0;
}
int main()
{
    read(T);
    while(T--)solve();
    return 0;
}