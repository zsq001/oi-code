#include<stdio.h>
#include<string.h>
using namespace std;

const int G=998244353;
int ho,n,m;
long long ans;
int sum[50],usem[510];
int a[110][510];

void xuan(int now,int k,int pls)
{
	if(k<=0){ans=(ans+pls)%G;return ;}
	if(now>n)return ;
	for(int i=now;i<=n-k+1;i++)
	{
		for(int j=1;j<=m;j++)
			if(usem[j]+1<=ho)
			{
				usem[j]++;
				xuan(i+1,k-1,(pls*a[i][j])%G);
				usem[j]--;
			}
	}
	return ;
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			sum[i]+=a[i][j];
		}
	for(int k=1;k<=n;k++)
	{
		ho=k/2;
		memset(usem,0,sizeof(usem));
		xuan(1,k,1);
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

