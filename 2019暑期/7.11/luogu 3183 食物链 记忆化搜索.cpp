#include<iostream>
#include<algorithm>
#define maxn 100010
using namespace std;
int n,m,cnt,ans,f[maxn],cd[maxn],rd[maxn],head[maxn];
struct Edge{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int x){
	if(f[x]) return;
	if(!cd[x]){
		f[x]=1;
		return;
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		f[x]+=f[v];
	}
}
int main(){
	int u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		add(u,v);
		cd[u]++;
		rd[v]++;
	}
	for(int i=1;i<=n;++i){
		if((!rd[i])&&(cd[i])){
			dfs(i);
			ans+=f[i];
		}
	}
	cout<<ans;
	return 0;
}
