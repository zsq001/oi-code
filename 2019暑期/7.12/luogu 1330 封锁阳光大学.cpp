#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1<<29
#define maxm 100010
#define maxn 10010
using namespace std;
typedef long long ll;
int ans,n,m,cnt,vis[maxn],c[maxn],sum[2],hl[maxn];
struct Edge{
    int u,v,ne;
}e[maxm<<1];
void add(int u,int v)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].ne=hl[u];
    hl[u]=cnt;
}
bool dfs(int x,int col)
{
    vis[x]=1;
    c[x]=col;
    sum[col]++;
    for(int i=hl[x];i;i=e[i].ne){
        int v=e[i].v;
        if(vis[v]&&(c[v]==c[x])) return false;
        else if(!vis[v])
            if(!dfs(v,col^1)) return false;
    }
    return true;
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) c[i]=-1;
    while(m--){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        sum[0]=sum[1]=0;
        if(!dfs(i,0)){
            puts("Impossible");
            return 0;
        }
        ans+=min(sum[0],sum[1]);
    }
    printf("%d",ans);
    return 0;
}
