#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=998244353;
int n,m;
long long a[110][2100];
int l[2100];
bool lie[2100];
long long ans;
long long u;
void cal(int x,int y,int yx,int k,long long now)
{
	if(k==1)
	{
		ans+=now;
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(lie[j]==true)continue;
			if(a[i][j]!=0)
			{
				now*=(a[i][j]%mo);
				now%=mo;
					l[j]++;
				if(l[j]==yx)lie[j]=true;
				cal(i,j,yx,k-1,now);
				now=a[x][y];
				lie[j]=false;
				l[j]--;
			}
			
		}
	}
}
void gd(int k)
{
	int mx=k/2;
	long long sum;
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
				l[j]++;
				if(l[j]==mx)lie[j]=true;
				sum=a[i][j];
				cal(i,j,mx,k,sum);
				lie[j]=false;
				l[j]=0;
			}
		}
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=2;i<=n;i++)
	{
		gd(i);
	}
	printf("%lld",ans);
} 
