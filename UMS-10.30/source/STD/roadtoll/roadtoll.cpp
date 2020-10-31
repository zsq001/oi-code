#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn=255;
const int maxm=10005;
const int inf=1e8;
int n,m,K,u,v,w,vis[maxn],dist[maxn][maxn],ans[maxn][maxn],c[maxn];
struct data{
    int w,id;
    friend bool operator <(data a,data b)
    {
        return a.w<b.w;
    }
}cc[maxn];
void floyd(){
    sort(cc+1,cc+1+n);
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        dist[i][j]=min(dist[i][cc[k].id]+dist[cc[k].id][j],dist[i][j]);
        ans[i][j]=min(ans[i][j],dist[i][j]+max(cc[k].w,max(c[i],c[j])));
    }
}
void solve()
{
    floyd();
    for(int i=1;i<=K;i++){
        scanf("%d%d",&u,&v);
        printf("%d\n",ans[u][v]);
    }
}
int main()
{
  freopen("roadtoll.in","r",stdin);
  freopen("roadtoll.out","w",stdout);
    scanf("%d%d%d",&n,&m,&K);
    memset(ans,0x3f,sizeof(ans));
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        scanf("%d",&cc[i].w);
        c[i]=cc[i].w;
        cc[i].id=i;
        ans[i][i]=cc[i].w,dist[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v]=dist[v][u]=min(dist[u][v],w);
    }
    solve();
    return 0;
}