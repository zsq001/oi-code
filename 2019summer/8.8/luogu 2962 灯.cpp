#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define mod 1000000007
#define ll long long 
using namespace std;
int n,m,ans=1<<29,f,up;
ll base[41],p[41],ed;
map<ll,int>ys;
void dfs(int x,ll now,int tot)
{
	if(x==up+1){
		if(now==ed) ans=min(ans,tot);
		if(!f){
			int t=ys[now];
			if(!t||t>tot) ys[now]=tot;
		}
		else{
			int t=ys[ed-now];
			if(!t) return;
			ans=min(ans,tot+t);
		}
		return;
	}
	dfs(x+1,now,tot);
	dfs(x+1,now^p[x],tot+1);
}
int main()
{
	int x,y;
	base[1]=1;
	for(int i=2;i<=40;++i) base[i]=base[i-1]<<1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		p[x]+=base[y],p[y]+=base[x];
	}
	for(int i=1;i<=n;++i) p[i]+=base[i];
	ed=base[n+1]-1;
	up=n/2+1;
	dfs(1,0,0);
	f=1;
	up=n;
	dfs(n/2+1,0,0);
	printf("%d\n",ans);
	return 0;
}
