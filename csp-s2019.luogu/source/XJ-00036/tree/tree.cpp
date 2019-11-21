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
const int maxn=2005;
struct node
{
    int v,next,u;
}e[maxn<<1],ed[maxn];
int n,w[maxn],cnt,head[maxn],pos[maxn];
void ins(int u,int v){e[++cnt].v=v;e[cnt].next=head[u];head[u]=cnt;}
namespace sub1
{
    bool vis[20];
    int ans[20],tmp[20],q[20],tp[20];
    void dfs(int dep)
    {
        if(dep==n-1)
        {
            for(int i=1;i<=n;i++)tmp[i]=w[i];
            for(int i=1;i<n;i++)
                std::swap(tmp[ed[q[i]].u],tmp[ed[q[i]].v]);
            for(int i=1;i<=n;i++)tp[tmp[i]]=i;
            bool flag=true;
            for(int i=1;i<=n;i++)
                if(tp[i]>ans[i])
                {
                    flag=false;
                    break;
                }
                else if(tp[i]<ans[i])break;
            if(flag)for(int i=1;i<=n;i++)ans[i]=tp[i];
            return;
        }
        for(int i=1;i<n;i++)
            if(!vis[i])
            {
                vis[i]=true;
                q[dep+1]=i;
                dfs(dep+1);
                vis[i]=false;
            }
    }
    void work()
    {
        for(int i=1;i<=n;i++)ans[i]=n+1;
        dfs(0);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        puts("");
    }
}
void init()
{
    cnt=0;
    memset(head,0,sizeof(head));
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T;read(T);
    while(T--)
    {
        read(n);
        for(int i=1;i<=n;i++)
        {
            read(pos[i]);w[pos[i]]=i;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            read(u);read(v);
            ed[i].u=u;ed[i].v=v;
            ins(u,v);ins(v,u);
        }
        if(n<=10)sub1::work();
        init();
    }
    return 0;
}
