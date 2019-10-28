#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define len 100010
#define inf 1<<29
using namespace std;
int hl[len],i,j,k,pos,dis[len],vis[len],ans[len],MAX=0,V[len],U[len],W[len],cnt,N,m,X;
struct Edge{
    int v,w,n;
}x[len];
inline void init()
{
    memset(x,0,sizeof(x));
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(i=1;i<=N;++i) hl[i]=-1;
}
void add(int u,int v,int w)
{
    x[++cnt].v=v;
    x[cnt].w=w;
    x[cnt].n=hl[u];
    hl[u]=cnt;
}
void dijkstra(int s)
{
    for(i=1;i<=N;++i) dis[i]=inf;
    dis[s]=0;
    for(i=1;i<=N;++i){
        k=0;
        for(j=1;j<=N;++j) if(!vis[j]&&(!k||dis[k]>dis[j])) k=j;
        vis[k]=1;
        for(j=hl[k];j!=-1;j=x[j].n) if(!vis[x[j].v]&&(dis[k]+x[j].w<dis[x[j].v])) dis[x[j].v]=dis[k]+x[j].w;
    }
}
int main()
{
    cin>>N>>m>>X;
    init();
    for(i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        V[i]=u,U[i]=v,W[i]=w;
        add(u,v,w);
    }
    dijkstra(X);
    for(i=1;i<=N;++i) ans[i]=dis[i];
    init();
    for(i=1;i<=m;++i) add(U[i],V[i],W[i]);
    dijkstra(X);
    for(i=1;i<=N;++i){
        ans[i]+=dis[i];
        MAX=max(MAX,ans[i]);
    }
    cout<<MAX<<endl;
    return 0;
}
