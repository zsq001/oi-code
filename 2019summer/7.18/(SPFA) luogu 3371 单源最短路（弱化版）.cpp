#include<cstdio>
#include<queue>
#include<iostream>
#define inf 2147483647
using namespace std;
int n,m,s,cnt,hl[100010],vis[100010],dis[100010];
queue<int>Q;
struct Edge{
    int v,w,ne;
}e[500010];
void add(int u,int v,int w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].ne=hl[u];
    hl[u]=cnt;
}
void spfa()
{
    int x,v,w;
    vis[s]=1;
    dis[s]=0;
    Q.push(s);
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(int i=hl[x];i;i=e[i].ne){
            v=e[i].v,w=e[i].w;
            if(dis[x]+w<dis[v]){
                dis[v]=dis[x]+w;
                if(!vis[v]){
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
        vis[x]=0;
    }
}
int main()
{
    int u,v,w;
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(int i=1;i<=n;++i) dis[i]=inf;
    spfa();
    for(int i=1;i<=n;++i) cout<<dis[i]<<" ";
    return 0;
}
