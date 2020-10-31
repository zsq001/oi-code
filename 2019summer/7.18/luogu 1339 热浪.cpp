#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define inf 1<<29
using namespace std;
queue<int>q;
int hl[70000],vis[30000],dis[30000],head,i,T,C,TS,TE,cnt;
struct Edge{
    int v,w,n;
}e[70000];
void add(int u,int v,int w)
{
    e[++cnt].w=w;
    e[cnt].v=v;
    e[cnt].n=hl[u];
    hl[u]=cnt;
}
void spfa(int s)
{
    for(i=1;i<=T;++i) dis[i]=inf;
    vis[s]=1;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        head=q.front();
        for(i=hl[head];i!=-1;i=e[i].n){
            if(dis[head]+e[i].w<dis[e[i].v]){
                dis[e[i].v]=dis[head]+e[i].w;
                if(!vis[e[i].v]){
                    vis[e[i].v]=1;
                    q.push(e[i].v);
                }
            }
        }
        q.pop();
        vis[head]=0;
    }
}
int main()
{
    int u,v,w;
    cin>>T>>C>>TS>>TE;
    for(i=1;i<=C;++i) hl[i]=-1;
    for(i=1;i<=C;++i){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    spfa(TS);
    cout<<dis[TE]<<endl;
    return 0;
}
