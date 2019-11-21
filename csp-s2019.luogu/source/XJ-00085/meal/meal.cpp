#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#define oo 1000000007
#define N 500100
#define M 5010
using namespace std ;
struct edge{
	int u,v,val,next;
}e[N];
int cnt,head[N],dis[N],mtr[M],n,m,a[M][M],num[M][M],ans;
bool vis[N],vi5[N];
struct node{
	int dis;
	int pos;
	bool operator < (const node &x) const {
		return x.dis<dis;
	}
};
void add(int u,int v,int val){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<node> q;
void dijkstra(int x){
	memset(dis,0x7f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[x]=0;
	q.push((node){dis[x],x});
	mtr[x]=1;
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				mtr[v]=mtr[u];
				if(!vis[v]) q.push((node){dis[v],v});
			}
			else if(dis[v]==dis[u]){
				mtr[v]+=mtr[u];
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			num[i][j]=++cnt;
		}
	cnt=0;
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			for(register int k=i+1;k<=n;k++)
				for(register int l=1;l<=m;l++){
					if(j==l) continue;
					if(!a[i][j]) continue;
					if(!a[k][l]) continue;
					for(register int o=1;o<=a[i][j];o++){
						add(num[i][j],num[k][l],1);
					}
				}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			if(a[i][j]) dijkstra(num[i][j]);
			else continue;
			for(register int k=1;k<=n;k++){
				for(register int l=1;l<=m;l++){
					if(k==i and j==l) continue;
					if(mtr[num[k][l]]) ans++;
					ans%=998244353;
				}
			}
			memset(mtr,0,sizeof mtr);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
