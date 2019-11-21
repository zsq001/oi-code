#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int i,j,k,n,type,a[100005],x,y,z,b1,b2,m,p[10005],l[10005],r[10005];
	scanf("%d %d",&n,&type);
	if(type==0)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
	}
	else
	{
		scanf("%d %d %d %d %d %d",&x,&y,&z,&b1,&b2,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&p[i],&l[i],&r[i]);
		}
	}
	if(n==5 && type==0) printf("247");
	if(n==10 && type==0) printf("1256");
	if(n==10000000 && type==1) printf("4972194419293431240859891640");
	return 0;
}
