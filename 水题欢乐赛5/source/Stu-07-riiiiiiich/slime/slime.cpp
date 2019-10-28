#include<bits/stdc++.h>
#include<cstring>
using namespace std;
typedef long long ll;
ll ans=0;
struct ass{
	int v,u,next;
}a[100010];
int head[100010],cnt,vis[100010];
void add(int v,int u){
	a[++cnt].v=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int i,int x,int y,int n){
	if(x>n){
		dfs(i,x,y,n);
		return ;
	}
	else
	{
		for(int j=i;j<=n;++j){
			if(y){
				if(x==j)
				ans++;	
			}	
		}
	}
			
}
int main(){
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
	ll n,m,op;
	ll u,v;
	scanf("%lld %lld %lld",&n,&m,&op);
	for(int i=1;i<n;++i){
		
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		dfs(i,u,v,n);
	}
	printf("%d",ans);
	return 0;
}
