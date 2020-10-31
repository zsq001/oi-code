#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long ll;
int n,m,num,cnt,ans,vis[1010][1010],f[1010],head[1010],tmp[1010];
struct Edge{
	int v,w,next;
}e[1000010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int x){
	if(f[x]) return;
	f[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		f[x]=max(f[x],f[v]+1);	
	}
	ans=max(ans,f[x]);
}
int main()
{
    cin>>n>>m;
    while(m--){
    	cin>>num;
    	for(int i=1;i<=num;++i) cin>>tmp[i];
    	for(int i=1;i<num;++i)
    		for(int j=tmp[i]+1;j<tmp[i+1];++j)
    			for(int k=1;k<=num;++k)
    				if(!vis[j][tmp[k]]){
    					vis[j][tmp[k]]=1;
    					add(j,tmp[k]);
    				}
	}
	for(int i=1;i<=n;++i) 
		if(!f[i])
			dfs(i);
	cout<<ans;
    return 0;
}
