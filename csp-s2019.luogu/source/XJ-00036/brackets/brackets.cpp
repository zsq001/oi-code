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
const int maxn=5e5+7;
struct node
{
    int v,next;
}e[maxn];
int n,cnt,head[maxn],fa[maxn],sum[maxn],ans[maxn],pre[maxn];
long long Ans;
char s[maxn];
void ins(int u,int v){e[++cnt].v=v;e[cnt].next=head[u];head[u]=cnt;}
void dfs(int x)
{
    ans[x]=ans[fa[x]];
    if(s[x]==')')
    {
        int y=fa[x],z=fa[y];
        if(s[y]=='(')
        {
            sum[x]=sum[z]+1;
            if(s[z]=='(')pre[x]=z;
            else pre[x]=pre[y];
        }
        else 
        {
            if(pre[y])
            {
                int f=fa[pre[y]];
                sum[x]=sum[f]+1;
                if(s[f]=='(')pre[x]=f;
                else pre[x]=pre[f];
            }
        }
    }
    ans[x]+=sum[x];
    for(int p=head[x];p;p=e[p].next)
    {
        int v=e[p].v;
        dfs(v);
    }
    Ans^=(1ll*x*ans[x]);
}
int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    read(n);
    scanf("%s",s+1);s[0]=')';
    for(int i=2;i<=n;i++)
    {
        read(fa[i]);
        ins(fa[i],i);
    }
    dfs(1);
    printf("%lld\n",Ans);
    return 0;
}
