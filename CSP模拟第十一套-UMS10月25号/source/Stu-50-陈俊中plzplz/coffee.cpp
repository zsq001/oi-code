#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 100010
using namespace std;

int n,h,b,e,c[maxn],dp[maxn],flag[maxn];

int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(~scanf("%d%d%d%d",&n,&h,&b,&e))
	{
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		for(int i=1;i<=n;i++) dp[i]=1;
		int se,sb;
		if(b-h>1)  sb=b-h;
		else if(b-h<=1) sb=1;
		if(e+h<n) se=e+h;
		else if(e+h>=n) se=n;
		for(int i=sb;i<=se;i++)
		{
			for(int j=1;j<=h;j++)
			{
				if(c[i+j-1]>c[i]&&flag[i+j-1]==0) 
				{
					dp[i]++;
					dp[i+j-1]=0;
					flag[i+j-1]=1;
				}
				if(c[i+j]<=c[i])
				{
					break;
				}
			}
		}
		for(int i=b;i<=e;i++)
		{
			printf("%d ",dp[i]);
		}
		printf("\n");
	}
	return 0;
}
