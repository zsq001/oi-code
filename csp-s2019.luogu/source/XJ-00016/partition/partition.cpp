#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
long long ans=0,n,a[10000000],maxx[10000000],ta;

long long check(long long i,long long maxx)
{
	long long l=1,r=1;
//cout<<i<<" "<<maxx<<endl;
	while(1)
	{
		if(a[i-l]<a[i+r])
		{
		//	if(a[i-l]+a[i]>maxx)cout<<l<<" -"<<r<<endl;
			if(a[i-l]+a[i]>maxx)return i-l;
			else l++;
		}
		else
		{
		//	if(a[i+r]+a[i]>maxx)cout<<l<<" +"<<r<<endl;
			if(a[i+r]+a[i]>maxx)return i+r;
			else r++;
		}
	}
}
void find(long long c,long long b)
{
	long long t;
	if(c>b){t=c;c=b;b=t;}
	for(long long i=c;i<b;i++)
	{
		a[b]+=a[i];
		a[i]=-1;
	}
	for(long long i=b;i<=n;i++)if(maxx[i]<a[b])maxx[i]=a[b];
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld%lld",&n,&ta);
	maxx[0]=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(maxx[i-1]<a[i])maxx[i]=a[i];
		else maxx[i]=maxx[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]<maxx[i])find(i,check(i,maxx[i]));
	}
	
	
//	for(long long i=1;i<=n;i++)cout<<a[i]<<endl;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			ans+=a[i]*a[i];
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);return 0;
}
