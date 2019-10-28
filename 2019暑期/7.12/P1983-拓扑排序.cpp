#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 200010
using namespace std;
typedef long long ll;
queue<int>Q;
int n,m,num,cnt,ans,cd[1010],rd[1010],vis[1010][1010],f[1010],head[1010],tmp[1010];
struct Edge{
	int v,w,next;
}e[1000010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
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
    					cd[j]++;
						rd[tmp[k]]++; 
    				}
	}
	for(int i=1;i<=n;++i){
		f[i]=1;
		if(!rd[i]) Q.push(i);
	}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			rd[v]--;
			f[v]=max(f[v],f[x]+1);
			if(!rd[v]) Q.push(v);
		}
		ans=max(ans,f[x]);
	}
	cout<<ans;
    return 0;
}
