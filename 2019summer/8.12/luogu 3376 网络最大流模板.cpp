#include<bits/stdc++.h>
#define inf 1<<29
#define maxn 10010
using namespace std;
int t,head[maxn],dis[maxn],late[maxn],n,m,cnt;
queue<int>Q;
struct Edge{
	int v,c,next,re;
}e[200010];
void add(int u,int v,int c)
{
	int i=++cnt;
	int j=++cnt;
	e[i].v=v;
	e[j].v=u;
	e[i].c=c;e[j].c=0;
	e[i].next=head[u];
	e[j].next=head[v];
	e[i].re=j;e[j].re=i;
	head[u]=i;
	head[v]=j;
}
bool bfs(int s){
	for(int i=1;i<=n;++i) dis[i]=inf;
	dis[s]=0;
	Q.push(s);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(e[i].c&&(dis[v]>dis[x]+1)){
				dis[v]=dis[x]+1;
				Q.push(v);
			}
		}
	}
	return dis[t]<inf; 
}
int dfs(int x,int water){
	if(x==t) return water;
	for(int i=late[x];i;i=e[i].next){
		late[x]=i;
		int v=e[i].v;
		if(e[i].c&&(dis[v]==dis[x]+1)){
			int flow=dfs(v,min(water,e[i].c));
			if(flow){
				int j=e[i].re; 
				e[i].c-=flow;
				e[j].c+=flow;
				return flow;
			}
		}
	}
}
int dinic(int s){
	int ret=0,flow;
	while(bfs(s)){
		for(int i=1;i<=n;++i) late[i]=head[i];
		while(flow=dfs(s,inf)) ret+=flow;
	}
	return ret;
}
int main(){
	int u,v,c,s;
	cin>>n>>m>>s>>t;
	while(m--){
		cin>>u>>v>>c;
		add(u,v,c);
	}
	cout<<dinic(s)<<endl;
	return 0;
}
