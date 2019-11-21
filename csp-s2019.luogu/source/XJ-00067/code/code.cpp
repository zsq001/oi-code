#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,k;
int a[3]={0,0,1};
long long cal(int mi)
{
	int x=1;
	for(int i=1;i<=mi;i++)
	{
		x*=2;
	}
	return x;
}
void find(int now,int num)
{
	long long f=cal(now);
	if(now==1)
	{
		printf("%d",a[num]);
		return;
	}
	if(num>f/2)
	{
		printf("1");
		find(now-1,f-num+1);
	}
	if(num<=f/2)
	{
		printf("0");
		find(now-1,num);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long m=k+1;
	find(n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
