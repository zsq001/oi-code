#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int mod = 100000007;
int pri[1000001];
inline void create(int n)
{
	for(int i = 2;i<=n;i ++)
	{
		if(pri[i])continue;
		for(int j = i;j <= n/i;j++)pri[i*j] = 1;
	}
}
inline int  count(int n,int k)
{
	int cnt = 0;
	if(n%k == 0)
	{
		n/=k;
		cnt++;
		count(n/k,k);
	}
	if(n%k!=0)return cnt;
}
int main()
{
	int n;
	cin>>n;
	create(n);
	int flag = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(pri[i])flag++;
	}
	int ans = 1;
	for(int i = 1;i <= flag;i++ )
	{
		ans *= 2 * count(n,pri[i]) + 1;
		ans %= mod;
	}
	cout<<ans<<endl;
}
