#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int v,next; 
}e[1000010];
int head[1010],n1,n2,m,match[1010],vis[1010],cnt,ans; 
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u]; 
	head[u]=cnt; 
}
bool find(int x){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||find(match[v])){
			match[v]=x;
			return true;
		}
	}
	return false;
} 
int main()
{
	int u,v;
	cin>>n1>>n2>>m;
	while(m--){
		cin>>u>>v;
		if(u<=n1&&v<=n2) add(u,v);
	}
	for(int i=1;i<=n1;++i){
		memset(vis,0,sizeof(vis));
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
