#include<bits/stdc++.h>
#define ll long long
#define maxn 300010
using namespace std; 
int ans,cnt,n,m,op,coin,vis[maxn],son[maxn],head[maxn],deep[maxn],tong[maxn]; 
struct Edge{
	int v,next;
}e[4000010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	ans=max(ans,deep[x]);
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
	}
}
void dfs2(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(vis[v]) continue;
		dfs2(v);
	}
}
int rnd(){
	return 1ll*rand()*rand();
}
int main()
{
	freopen("slime10.in","w",stdout);
	srand(time(0));
	n=300000,m=299999,op=2;
	cout<<n<<" "<<m<<" "<<op<<endl;
	int u,v;
	if(op==1){
		for(int i=1;i<=m;++i){
			while(1){
				u=rnd()%n+1;
				v=rnd()%n+1;
				if(u==v) continue;
				//if(son[u]>20) continue;
				//if(son[v]>20) continue;
				son[u]++;
				son[v]++;
				cout<<u<<" "<<v<<endl;
				add(u,v);
				add(v,u);
				break;
			}
		}
		dfs2(1);
		for(int i=1;i<=n;++i) 
			if(!vis[i]) cout<<"!!!"<<" "<<i<<endl;
	}
	else{
		for(int v=2;v<=n;++v){
			while(1){
				u=rnd()%(v-1)+1;
				if(son[u]==2) continue;
				if(son[u]==1){
					coin=rand()%100000;
					if(coin) continue;
				}
				son[u]++;
				cout<<u<<" "<<v<<endl;
				add(u,v);
				add(v,u);
				break;
			}
		}
		dfs(1,0);
	}
	//cout<<ans<<endl;
	/*for(int i=1;i<=n;++i) tong[deep[i]]++;
	for(int i=1;i<=ans;++i) cout<<i<<" "<<tong[i]<<endl;*/
	return 0;
}
