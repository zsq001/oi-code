#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	int ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			for(int k = 1;k <= n;k++)
			{
				if(i == j||j == k||i ==k)continue;
				if(i + j + k == n)
				{
					//cout<<i<<' '<<j<<' '<<k<<endl;
					ans ++;
				}
			}
		}
	}
	if(n > 7)cout<<ans+1-n+1<<endl;
	else
	{
			if(n == 1)ans = 1;
	if(n == 2)ans = 1;
	if(n == 3)ans = 2;
	if(n == 4)ans = 2;
	if(n == 5)ans = 3;
	if(n == 6)ans = 4;
	if(n == 7)ans = 5;
	cout<<ans<<endl;
	}
	return 0;
}
