#include<bits/stdc++.h>
#define maxn 100010
#define inf 2147483647
using namespace std;
typedef long long ll;
struct Edge{
	int v,w,next;
}e[500010];
int n,m,cnt,minx,head[maxn],dis[maxn],vis[maxn];
priority_queue<pair<int,int> >Q;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijkstra(int s){
	for(int i=1;i<=n;++i)
		dis[i]=inf;
	dis[s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if((!vis[v])&&(dis[v]>dis[x]+w)){
				dis[v]=dis[x]+w;
				Q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main()
{
	int u,v,w,s;
	cin>>n>>m>>s;
	while(m--){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	dijkstra(s);
	for(int i=1;i<=n;++i) cout<<dis[i]<<" ";
    return 0;
}
