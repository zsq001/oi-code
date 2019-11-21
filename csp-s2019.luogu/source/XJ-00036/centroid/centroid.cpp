#include<cstdio>
#include<cstring>
#include<algorithm>
template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
    return;
}
const int maxn=3e5+7;
struct node
{
    int v,next;
    bool vis;
}e[maxn<<1];
int cnt,head[maxn],n,rt,d[maxn];
void ins(int u,int v){e[++cnt].v=v;e[cnt].next=head[u];head[u]=cnt;}
void init()
{
    cnt=0;rt=0;
    memset(head,0,sizeof(head));
}
namespace sub1
{
    int dep[maxn],pos[maxn];
    void dfs(int x,int fa)
    {
        pos[dep[x]]=x;
        for(int p=head[x];p;p=e[p].next)
        {
            int v=e[p].v;
            if(v==fa)continue;
            dep[v]=dep[x]+1;
            dfs(v,x);
        }
    }
    void work()
    {
        dfs(rt,0);
        long long ans=0;
        for(int i=1;i<=cnt;i+=2)
        {
            int x=e[i+1].v,y=e[i].v;
            if(dep[x]>dep[y])std::swap(x,y);
            if(dep[x]&1)ans+=(pos[dep[x]>>1]+pos[dep[x]+1>>1]);
            else ans+=pos[dep[x]>>1];
            if((n-dep[y])&1)ans+=pos[n-1+dep[y]>>1];
            else ans+=(pos[n-1+dep[y]>>1]+pos[n+dep[y]>>1]);
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    freopen("centroid.in","r",stdin);
    freopen("centroid.out","w",stdout);
    int T;read(T);
    while(T--)
    {
        read(n);
        for(int i=1;i<n;i++)
        {
            int u,v;
            read(u);read(v);
            ins(u,v);ins(v,u);
            d[u]++;d[v]++;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>2)flag=false;
            if(d[i]==1)rt=i;
        }
        if(flag)sub1::work();
        init();
    }
    return 0;
}
