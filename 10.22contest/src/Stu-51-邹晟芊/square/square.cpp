#include<iostream>
#include<cstdio>
using namespace std;
int a[200010];
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,sum1=0,sum2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2==1)
		sum1+=a[i];
		else
		sum2+=a[i];
	}
	int c,k;
	if(sum1>sum2)
	{
		c=sum1-sum2;
		k=1;
	}
	else
	{
		c=sum2-sum1;
		k=2;
	}
	int ans=0;
	for(int i=k;i<=n;i+=2)
	{
		if(a[i]==c)
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
