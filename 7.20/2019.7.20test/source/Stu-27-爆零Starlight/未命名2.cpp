#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define inf 2147483647
struct edge{
	int w,v,next;
}e[maxn];
queue <int> q;
int cnt,n,op,s,x;
int head[maxn],dis[maxn],vis[maxn],a1[maxn],a2[maxn];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void spfa(){
	for(int i=1;i<=n;++i) dis[i]=inf;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(dis[v]>dis[x]){
				dis[v]=dis[x];
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}

int main(){
	cin>>n>>op;
	for(int i=1;i<=n;++i){
		cin>>a1[i]>>a2[i];
		add(1,n);
	}
		
	spfa();
	if(op==0){
		for(int i=1;i<=n;++i){
			cout<<dis[i]<<endl;
		}
	
	}
	
	return 0;
}
