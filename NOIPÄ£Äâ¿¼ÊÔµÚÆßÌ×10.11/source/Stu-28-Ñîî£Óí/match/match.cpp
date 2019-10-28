#include<bits/stdc++.h>
#define N 2000100
using namespace std ;
struct edge{
	int u,v,next;
}e[N<<1];
int n,m,x,y,a[N<<1],head[N<<1],cnt,match[N<<1],ans;
bool vis[N<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool findd(int x){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||findd(match[v])){
			match[v]=x;
			return true;
		}
	}
	return false;
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1+n;i<=n+m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1+n;j<=n+m;j++){
			if(a[j]>a[i]+y) break;
			if(a[j]>=a[i]-x)
				add(i,j);
		}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if(findd(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
