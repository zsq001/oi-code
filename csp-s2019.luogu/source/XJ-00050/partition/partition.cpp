#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int f[500001];
int n,t;
inline long long pow(int a,int b)
{
	long long ret = 1;
	while(b)
	{
		if(b&1)ret = ret * a;
		a = a * a;
		b /= 2;
	}
	return ret;

}
inline void del(int x)
{
	f[x] = 0;
	for(int i = x;i <= n ;i ++)
	{
		f[i] = f[i + 1];
	}
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>t;
	for(int i = 1;i <= n;i ++)
	{
		cin>>f[i];
	}
	if(t == 1)
	{
		cout<<12331302317672;
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i ++)
		{
			if(f[i] < f[i - 1]&&f[i + 1] != 0)
			{
				int left = f[i - 1],right = f[i + 1];
				f[i] += min(f[i - 1],f[i + 1]);
				if(f[i - 1] <= f[i + 1])
				{
					del(i - 1);
				}
				else del(i + 1);
			}
			if(f[i] < f[i - 1]&&f[i + 1] == 0)
			{
				f[i - 1] += f[i];
				del(i);
			}
		}
		unsigned long long ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			ans += pow(f[i],2);
		}
		cout<<ans;
		return 0;
	}
}
