#include<iostream>
using namespace std;
#define mmm 2000
typedef int int_;
#define int long long
int place[mmm],num[mmm],f[20][mmm][mmm>>1],n,cnt=0,k;
void dfs(int a,int sum,int b)
{
	if(b>=n)
	{
		place[++cnt]=a;
		num[cnt]=sum;
		return ;
	}
	dfs(a,sum,b+1);
	dfs(a+(1<<b),sum+1,b+2);
}
int_ main()
{
	cin>>n>>k;
	dfs(0,0,0);
	for(int i=1;i<=cnt;i++)
	f[1][i][num[i]]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<=cnt;j++)
	for(int k_=1;k_<=cnt;k_++)
	{
		if(place[j]&place[k_])
		continue;
		if((place[j]<<1)&place[k_])
		continue;
		if(place[j]&(place[k_]<<1))
		continue;
		for(int w=k;w>=num[j];w--)
		{
			f[i][j][w]+=f[i-1][k_][w-num[j]];
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
	ans+=f[n][i][k];
	cout<<ans;
	return 0;
}
