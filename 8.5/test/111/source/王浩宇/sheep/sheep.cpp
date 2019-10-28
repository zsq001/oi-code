#include<cstdio>
#include<algorithm>
typedef int int_;
#define int long long
#define maxn 500050
using namespace std;
int n,m,a[maxn],ans;
void dfs(int now)
{
	if(a[now+a[now]]==0)return;
	else 
	{   
		ans++;
		dfs(now+a[now]);
	}
	return;
}
int_ main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%lld",&n);
	int f,p,k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&f);
		if(f==1)
		{
			scanf("%lld",&p);
			dfs(p);
			printf("%lld\n",ans);
			ans=0;
		}
		if(f==2)
		{
			scanf("%lld%lld",&p,&k);
			a[p+1]=k;
		}
	}
}
