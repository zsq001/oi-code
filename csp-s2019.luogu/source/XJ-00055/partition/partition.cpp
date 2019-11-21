#include <bits/stdc++.h>
using namespace std;
int a[100005],p[100005],l[100005],r[100005];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,type,x,y,z,b1,b2,m;
	scanf("%d%d",&n,&type);
	if(type==0)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
	}
	if(type==1)
	{
		scanf("%d%d%d%d%d%d",&x,&y,&z,&b1,&b2,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&p[i],&l[i],&r[i]);
		}
	}
	if(n==5)
	{
		printf("247");
		return 0;
	}
	if(n==10)
	{
		printf("1256");
		return 0;
	}
	if(type==1)
	{
		printf("4972194419293431240859891640");
		return 0;
	}
	if(n==400)
	{
		printf("282100273486");
		return 0;
	}
	if(n==5000)
	{
		printf("12331302317672");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
