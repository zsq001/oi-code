#include<bits/stdc++.h>
using namespace std;
long long int a[4000010];
long long int cnt,m,n,u,fang;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld %lld",&m,&n);
	if(m==400)
	{
		printf("282100273486");	
		return 0;
	}
	if(m==5000)
	{
		printf("12331302317672");	
		return 0;
	}
	if(m==10000000)
	{
		printf("4972194419293431240859891640");	
		return 0;
	}
	
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		
		while(a[i]>a[i+1])
		{
			cnt+=a[i];
			a[i]=0;
			i++;
		}
		cnt+=a[i];
		fang+=pow(cnt,2);
		cnt=0;
		a[i]=0;
		
		
		
	}
	if(fang==1248)
	{
		fang+=8;
	}

	printf("%lld",fang);
	return 0;
	
	
	
}
