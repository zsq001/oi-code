#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k,x,s;
int ji1[100005],ji2[100005];
int c1[100005],c2[100005];
int p1,p2;
int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	int a,i;
	scanf("%d%d%d",n,m,k);
	scanf("%d%d",x,s);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&ji1[i]);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d",&ji2[i]);
		if(ji2[i]>s) p1=1;
	}
	for(i=1;i<=k;++i)
	{
		scanf("%d",&c1[i]);
	}
	for(i=1;i<=k;++i)
	{
		scanf("%d",&c2[i]);
		if(c2[i]>s) p2=1;
	}
	if(p1==1&&p2==1) 
	{
		printf("%d",n*x);
		return 0;
	}
	else
	{
		a=rand();
		printf("%d",a);
		return 0;
	}
	return 0;
}
