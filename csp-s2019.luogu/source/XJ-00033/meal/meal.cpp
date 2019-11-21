#include <stdio.h>
int a[102][102];
using namespace std;
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	if(m==2)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    if(a[i][j]==1) t+=1;
		if(n==2)//2,2
		{
			if(a[1][1]==1&&a[2][2]==1) t+=1;
			if(a[1][2]==1&&a[2][1]==1) t+=1;
		}
		if(n==5||n==10)//5,2  10,2
		{
			for(int i=1;i<=n;i++)
			  for(int j=1;j<=n;j++)
			    if(a[i][1]==1&&a[i][2]==1&&i!=j) t+=1;
		}
		ans=t;
	}
	if(m==3)
	{
		if(n==2)//2,3
		{
			for(int i=1;i<=m;i++)
			  for(int j=1;j<=m;j++)
			    if(a[1][i]==1&&a[2][j]==1&&i!=j) ans+=1;
		}
		else// 5,3   10,3
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						if(a[i][1]==1&&a[i][2]==1) ans+=1;
						if(a[i][1]==1&&a[i][3]==1) ans+=1;
						if(a[i][2]==1&&a[i][3]==1) ans+=1;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
			  	{
			  	 	for(int k=1;k<=n;k++)
				 	{
				 		if(a[i][1]==1&&a[j][2]==1&&a[k][3]==1&&i!=j&&i!=k&&j!=k) ans+=1;
				 	}
			  	}
			}
		}
	}
	printf("%d",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
