#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define maxn 2050
using namespace std;

int inf=1e9+7,n,m,vis[maxn],head[maxn],cnt,flag[maxn];

priority_queue<pair<int,int> >Q;
double dis[maxn];

struct node{
	int v,next,w;
}e[maxn<<2];

void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}

void dij(){
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[1]=0;
	Q.push(make_pair(0,1));
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if( (!vis[v]) && ( (dis[v]) /(flag[v]) ) > ( (dis[x]+w) /(flag[x]+1) ) ){
				dis[v]=(dis[x]+w);
				flag[v]=flag[x]+1;
				Q.push(make_pair(-dis[v],v));
			}
		}
	}
}

int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	flag[1]=1;
	dij();
	dis[n]=(dis[n]/flag[n]);
	printf("%.3f",dis[n]);
	return 0;
}
