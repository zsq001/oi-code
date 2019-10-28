#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define mmm 10000
using namespace std;
queue<int> q;
struct node{
	int u,v,w,ne;
}e[10000000];
int ans,n,m,hl[mmm],cnt,vis[mmm],dis[mmm],dis1[mmm],dis2[mmm],minl;
void add(int x,int y,int w)
{
	e[++cnt].u=x;
	e[cnt].v=y;
	e[cnt].w=w;
	e[cnt].ne=hl[x];
	hl[x]=cnt;
}
void spfa(int s)
{
    memset(dis,127/3,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();
        for(int i=hl[x];i;i=e[i].ne){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[x]+w){
                dis[v]=dis[x]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        q.pop();
        vis[x]=0;
    }
}
int spfa2(int s,int a,int b)
{
    memset(dis,127/3,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();
        for(int i=hl[x];i;i=e[i].ne){
            int v=e[i].v,w=e[i].w;
            if((a==x&&b==v)||(a==v&&b==x)) continue;
            if(dis[v]>dis[x]+w){
                dis[v]=dis[x]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        q.pop();
        vis[x]=0;
    }
    return dis[n];
}
int main()
{
	int i,x,y,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&w);
        add(x,y,w);
        add(y,x,w);
    }
    spfa(1);
    for(i=1;i<=n;++i) dis1[i]=dis[i];
    minl=dis1[n];
    spfa(n);
    for(i=1;i<=n;++i) dis2[i]=dis[i];
    for(i=1;i<=cnt;++i){
        int u=e[i].u,v=e[i].v;
        if(dis1[u]+e[i].w+dis2[v]==minl) 
		ans=max(ans,spfa2(1,u,v));
    }
    printf("%d\n",ans);
    return 0;
}
