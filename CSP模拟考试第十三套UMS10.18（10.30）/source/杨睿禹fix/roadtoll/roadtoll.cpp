#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define N 200010
using namespace std ;
struct edge{
	int u,v,next,val;
}e[N];
struct node{
	int dis;
	int pos;
	bool operator <(const node &x) const{
		return x.dis<dis;
	}
};
int cnt,head[N],dis[N],nxt[N],vis[N],n,m,k,val[N],ans,maxpoint[N][3];
void add(int u,int v,int val){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
queue<int> q;
void findd(int x){
	memset(dis,0x7f,sizeof dis);
	memset(maxpoint,0,sizeof maxpoint);
	dis[x]=val[x];
	maxpoint[x][1]=val[x];
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		maxpoint[u][1]=max(maxpoint[u][2],maxpoint[u][1]);
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			maxpoint[v][2]=max(maxpoint[u][1],val[v]);
			if(dis[v]>dis[u]+e[i].val-maxpoint[u][1]+maxpoint[v][2]){
				dis[v]=dis[u]+e[i].val-maxpoint[u][1]+maxpoint[v][2];
				q.push(v);
			}
		}
	} 
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("roadtoll.in","r",stdin);
	freopen("roadtoll.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		findd(u);
		cout<<dis[v]<<endl;
		ans=0;
	}
}
