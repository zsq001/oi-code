#include<iostream>
#include<cstdio>
#include<cmath>
#define mmm 1000
#define mod 998244353
typedef int int_;
#define int long long
using namespace std;
int n,m;
int a[mmm][mmm],ans=0,use[mmm],vis[mmm][mmm];
void dfs(int way)
{
	if(way>n)
		return ;
	for(int i=1; i<=m; i++) 
	{
		if(a[i][way])
		{
			vis[i][way]=1;
			use[i]++;
			if(use[i]>floor(n/2))
			{
				use[i]--;
				continue;
			}
			dfs(way+1);
			use[i]--;
			vis[i][way]=0;
			ans++;
		}
	}
	return ;
}
int_ main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);//ctrl+wÊÔÊÔ¾ÍÊÅÊÀ 
	cin>>n>>m;//2 3
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[j][i];
		}
	}
	for(int i=1; i<=m; i++)
	{
		if(a[i][1])
		{
			use[i]++;
			vis[i][1]=1;
			dfs(2);
			use[i]--;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
