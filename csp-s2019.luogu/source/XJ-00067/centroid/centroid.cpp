#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
long long cnt=1;
long long ans;
long long fa[50000];
bool f[50000];
void cal(long long now,bool IO)
{
	if(cnt==n+1)
	{
		return;
	}
	if(IO==true)
	{
		if(cnt==1||cnt==n)
		{
			ans+=2*now;
		}
		if((cnt>=2&&cnt<=(n/2)-1)||(cnt<=n-1&&cnt>=(n/2)+2))
		{
			ans+=3*now;
		}
		if((cnt==n/2)||(cnt==n/2+1))
		{
			ans+=2*now;
		}
		cnt++;
		cal(fa[now],1);
	}
	if(IO==false)
	{
		if(cnt==1||cnt==n)
		{
			ans+=2*now;
		}
		if((cnt>=2&&cnt<=(n/2))||(cnt<=n-1&&cnt>=(n/2)+2))
		{
			ans+=3*now;
		}
		if(cnt==(n/2)+1)
		{
			ans+=2*now;
		}
		cnt++;
		cal(fa[now],0);
	}
}
int main()
{
	int t;
	long long u,v;
	long long g;
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		cnt=1;
		for(int i=1;i<=n-1;i++)
		{
			scanf("%lld%lld",&u,&v);
			fa[v]=u;
			f[u]=true;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]==false)
			{
				g=i;
				break;
			}
		}
		if(n%2==0)
		cal(g,1);
		else cal(g,0);
		memset(f,false,sizeof(f));
		memset(fa,0,sizeof(fa));
		printf("%lld\n",ans);
		ans=0;
	}
}
