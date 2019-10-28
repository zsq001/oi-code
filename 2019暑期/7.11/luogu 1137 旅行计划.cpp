#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 100010
using namespace std;
int head[maxn],cnt,n,m,f[maxn],rd[maxn];
queue<int>Q;
struct Edge{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	int u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		add(u,v);
		rd[v]++;
	}
	for(int i=1;i<=n;++i)
		if(!rd[i]){
			f[i]=1;
			Q.push(i);
		}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=e[i].next){
			v=e[i].v;
			rd[v]--;
			if(!rd[v]){
				Q.push(v);
				f[v]=max(f[v],f[x]+1);
			}
		}
	}
	for(int i=1;i<=n;++i) cout<<f[i]<<endl;
	return 0;
}
