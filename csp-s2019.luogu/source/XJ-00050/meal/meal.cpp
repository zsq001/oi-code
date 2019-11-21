#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
long long a[101][4];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			cin>>a[i][j];
		}
	}
	if( m == 2)
	{
		unsigned long long ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i+1;j <= n;j ++)
			{
				ans += a[i][1]*a[j][2];
			}
		}
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i + 1;j <= n ;j ++)
			{
				ans += a[i][2] * a[j][1];
			}
		}
		cout<<ans%998244353;
		return 0;
	} 
	if(m == 3)
	{
		unsigned long long ans = 0;
		ans%=998244353;
		for(int i = 1;i <= n; i++)
		{
			for(int j = i+1;j <= n;j ++)
			{
				ans += a[i][1] * a[j][2];
				ans%=998244353;
				ans += a[i][1] * a[j][3];
				ans%=998244353;
				ans += a[i][2] * a[j][1];
				ans%=998244353;
				ans += a[i][2] * a[j][3];
				ans%=998244353;
				ans += a[i][3] * a[j][1];
				ans%=998244353;
				ans += a[i][3] * a[j][2];
				ans%=998244353;
				ans %= 998244353;
			}
			ans %= 998244353;
		}
		ans%=998244353;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i + 1;j <= n;j ++)
			{
				for(int k = j + 1;k <= n;k ++)
				{
					ans += a[i][1] * a[j][2] * a[k][3];
					ans%=998244353;
					ans += a[i][1] * a[j][3] * a[k][2];
					ans%=998244353;
					ans += a[i][2] * a[j][1] * a[k][3];
					ans%=998244353;
					ans += a[i][2] * a[j][3] * a[k][1];
					ans%=998244353;
					ans += a[i][3] * a[j][1] * a[k][2];
					ans%=998244353;
					ans += a[i][3] * a[j][2] * a[k][1];
					
					ans%=998244353;
				}
				ans%=998244353;
			}
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
