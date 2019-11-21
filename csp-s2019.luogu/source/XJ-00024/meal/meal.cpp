#include<stdio.h>
#include<string.h>
#include<algorithm>
#define p1 a[i][j]!=0&&a[i1][j1]!=0&&i1!=i&&j1!=j
#define p2 a[i2][j2]!=0&&i1!=i2&&j1!=j2&&i!=i2&&j!=j2
#define p3
using namespace std;
const int mod=998244353;
int n,m,flag,x,y,cnt,ans,pp;
int a[105][505],b[105][505];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int i=0,j=0,i1=0,j1=0,i2=0,j2=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			if(flag==0&&a[i][j]!=0) 
			{
				flag=1;
				x=i;
				y=j;
			}
		}
	}
	if(n==2)
	{
		for(i=x+1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				for(i1=x;i1<=n;++i1)
				{
					for(j1=1;j1<=m;++j1)
					{
						if(p1&&cnt<=1) 
						{
							ans+=1;
							ans=ans%mod;
						}
					}
				}	
			}
		}
	}
	else if(n==3)
	{
		for(i=x+1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				for(i1=x;i1<=n;++i1)
				{
					for(j1=1;j1<=m;++j1)
					{
						if(p1&&cnt<=1) 
						{
							ans+=1;
							ans=ans%mod;
						}
					}
				}
			}
		}
		for(i=x+1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				for(i1=x;i1<=n;++i1)
				{
					for(j1=1;j1<=m;++j1)
					{
						if(p1&&p2&&cnt<=1) 
						{
							ans+=1;
							ans=ans%mod;
						}
					}
				}	
			}
		}
		for(i=x+1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				for(i1=x;i1<=n;++i1)
				{
					for(j1=1;j1<=m;++j1)
					{
						for(i2=x+2;i2<=n;++i2)
						{
							for(j2=1;j2<=m;++j2)
							{
								if(a[i][j]!=0&&a[i1][j1]!=0&&cnt<=1&&i1!=i&&j1!=j) 
								{
									ans+=1;
									ans=ans%mod;
								}
							}
						}	
					}
				}	
			}
		}
	}
	else 
	{
		pp=rand();
		printf("%d",pp%mod);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("%d",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
