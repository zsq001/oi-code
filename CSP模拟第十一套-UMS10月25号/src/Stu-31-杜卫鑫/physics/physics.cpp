#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
struct node{
	ll a,t;
}x[100005];
ll v,vis[100005],mmax,ans;
bool cmp(node q,node w)
{
	if(q.t==w.t)return q.a>w.a;
	return q.t>w.t;
}
void dfs(int dep)
{
	if(dep>n){mmax=max(mmax,ans);return ;}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			ans+=v*x[i].t;
			v+=x[i].a*x[i].t;
			dfs(dep+1);
			vis[i]=0;
			v-=x[i].a*x[i].t;
			ans-=v*x[i].t;
		}
}
int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i].a,&x[i].t);
	}
	ll tmp;
	if(n<=5)
	{
		v=0;ans=0;
		dfs(1);
		v=ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=v*x[i].t;
			v+=x[i].a*x[i].t;
		}
		tmp=ans;
		printf("%.1lf",(double)(mmax-ans));
	}
	else
	{
		sort(x+1,x+n+1,cmp);
		v=mmax=0;
		for(int i=1;i<=n;i++)
		{
			mmax+=v*x[i].t;
			v+=x[i].a*x[i].t;
		}
		printf("%.1lf",(double)(mmax-tmp));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
