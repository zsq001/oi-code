#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;
const int M = 2100;
const double INF = 1e20;
const double eps = 1e-4;
struct Edge{int v,nxt; double w,x;}e[M];
int head[N]; double dis[N]; bool vis[N];
queue<int> q; int n,m,cnt=0;

inline int read()
{
	int x=0,t=1; char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return t*x;
}

void Addedge(int u,int v,double w)
{
	e[++cnt].v=v; e[cnt].x=w;
	e[cnt].nxt=head[u]; head[u]=cnt;
}

bool Spfa(double x)
{
	for(int i=1;i<=cnt;i++) e[i].w=e[i].x-x;
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[0]=0; q.push(0); vis[0]=true;
	while(!q.empty()){
		int u=q.front(); q.pop(); vis[u]=false;
		for(int i=head[u];i;i=e[i].nxt)
			if(dis[u]+e[i].w<dis[e[i].v]-eps){
				dis[e[i].v]=dis[u]+e[i].w;
				if(!vis[e[i].v]) q.push(e[i].v),vis[e[i].v]=true;
			}
	}
	return dis[n]<-eps;
}

int main()
{
	int u,v,w;
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		u=read(); v=read(); w=read();
		Addedge(u,v,w);
	}
	Addedge(0,1,0);
	double l=0,r=1e3;
	while(r-l>=eps){
		double mid=(l+r)/2.0;
		if(Spfa(mid)) r=mid;
		else l=mid;
	}
	printf("%.3lf\n",l);
	return 0;
}
