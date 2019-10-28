#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 100010
using namespace std;
queue<int>Q;
int n,m,cnt,ans,f[maxn],cd[maxn],rd[maxn],head[maxn];
struct Edge{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
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
	for(int i=1;i<=n;++i)
		if((!rd[i])&&(cd[i])){
			Q.push(i);
			f[i]=1;
		}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			f[v]+=f[x];
			rd[v]--;
			if(!rd[v]) Q.push(v);
		}
		if(!cd[x]) ans+=f[x];
	}
	cout<<ans;
	return 0;
}
