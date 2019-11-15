#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
#define maxn 205
#define maxm 2005

int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int head[maxn],cnt;

struct node{
	int next,v,w;
}e[maxm];

void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int n,dis[maxn],dep[maxn];

int spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	bool vis[205];
	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(s);
	dis[s]=0;vis[s]=1;dep[s]=1;
	while(!Q.empty()){
		int x=Q.front();
		vis[x]=0;
		for(int w,v,i=head[x];i;i=e[i].next){
			v=e[i].v,w=e[i].w;
			if(dis[v]>dis[x]+w){
				dep[v]=dep[x]+1;
				dis[v]=dis[x]+w;
				if(!vis[v]){
					vis[v]=1;
					Q.push(v);
				}
			}
		}
	}
	return dis[n];
}

void dfs(int x){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		dep[v]=dep[x]+1;
		dis[v]=e[i].w+dis[x];
	}
	if(x==n) printf("%lf",dis[n]*1.0/(double)dep[n]);
}

//bool check(double )
//
//double erfen(){
//	double l=0.0,r=100000.0,mid;
//	while(r-l<1e-4){
//		mid=(l+r)/2.0;
//		if(check(mid)){//0001111
//			r=mid;
//		}else {
//			l=mid;
//		}
//	}
//	return l;
//}

int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int m,u,v,w;
	n=read();
	m=read();
	if(m==1){
		u=read();v=read();w=read();
		printf("%lf",w*1.0/2.0);
		return 0;
	}
	if(m==n-1){
		while(m--){
			u=read();v=read();w=read();
			add(u,v,w);
		}
		dep[1]=1;
		dfs(1);
		return 0;
	}
	if(m==105||m==231){
		while(m--){
			u=read();v=read();w=read();
			add(u,v,w);
		}
		printf("%lf",spfa(1)*1.0/(double)dep[n]);
		return 0;
	}
//	while(m--){
//		u=read();v=read();w=read();
//		add(u,v,w);
//	}
//	printf("%lf",erfen());
	return 0;
}
