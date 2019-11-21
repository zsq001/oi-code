#include<iostream>
#include<stdio.h>
using namespace std;
int a[110][2010];
int main()
{
	int n,m,i,j,ans=0,k;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		int c=1;
		for(j=1;j<=m;j++)
		{
			if(a[i+c][j+1]>0)
			{
				if(a[i+c][j-1]>0)
				{
					ans+=a[i][j]*(a[i+c][j-1]+a[i+c][j+1]);
				}
				else
				{
					ans+=a[i][j]*a[i+c][j+1];	
				}
			}
			if(a[i+c][j-1]>0)
			{
				if(a[i+c][j+1]>0)
				{
					ans+=a[i][j]*(a[i+c][j-1]+a[i+c][j+1]);
				}
				else
				{
					ans+=a[i][j]*a[i+c][j-1];	
				}
			}
			c++;
		}
	}
	int answer=ans%998244353;
	cout<<answer<<endl;
	return 0;
}
