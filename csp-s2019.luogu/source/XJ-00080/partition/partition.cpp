#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1001];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	long long b=0,c=0;int i,type=0,n=0;
	cin>>n>>type;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i+1])
		{
			a[i]+=a[i+1];
			a[i+1]=0;
		}
	}
	for(i=1;i<=n;i++)
{
	c=pow(a[i],2);
	b+=c;
}
	cout<<b<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
