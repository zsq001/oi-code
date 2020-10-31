#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#define maxn 10010
#define inf 1<<29
#define ll long long
using namespace std;
queue<int>Q;
int n,m,S,T,k,head[maxn],headc[maxn],cnt,dis[maxn],vis[maxn],tot[maxn];
struct Edge{
	int v,w,next;
}e[100010],ec[100010];
struct Node{
	int x,f,g;
	Node(int a,int b,int c){x=a,f=b,g=c;}
	bool operator<(const Node &x)const{return x.f<f;}
};
priority_queue<Node>Qu;
void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
	ec[cnt].v=u;
	ec[cnt].w=w;
	ec[cnt].next=headc[v];
	headc[v]=cnt;
}
void spfa(int s)
{
	for(int i=1;i<=n;++i) dis[i]=inf;
	dis[s]=0;
	vis[s]=1;
	Q.push(s);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		vis[x]=0;
		for(int i=headc[x];i;i=ec[i].next){
			int v=ec[i].v,w=ec[i].w;
			if(dis[v]>dis[x]+w){
				dis[v]=dis[x]+w;
				if(!vis[v]){
					vis[v]=1;
					Q.push(v);
				}
			}
		}
	}
}
int A_star(int s){
	if(dis[s]==inf) return -1;
	if(s==T) k++;
	Qu.push(Node(s,dis[s],0));
	while(!Qu.empty()){
		Node now=Qu.top();
		Qu.pop();
		int x=now.x;
		tot[x]++;
		if(tot[T]==k) return now.g;
		if(tot[x]>k) continue;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]==inf) continue;
			Node next(0,0,0);
			next.x=v;
			next.g=now.g+w;
			next.f=next.g+dis[v];
			Qu.push(next);
		}
	}
	return -1;
}
int main()
{
	int u,v,w;
	cin>>n>>m;
	while(m--){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	cin>>S>>T>>k;
	spfa(T);
	cout<<A_star(S)<<endl;
	return 0;
}
