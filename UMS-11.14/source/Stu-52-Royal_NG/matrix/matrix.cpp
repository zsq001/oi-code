#include<stdio.h>
struct hang{
	int tot=0,num;
}a[1100];
struct lie{
	int tot=0,num;
}b[1100];
int now;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
		{
			a[y].tot=++now;
			a[y].num=z;
		}
		else
		{
			b[y].tot=++now;
			b[y].num=z;	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i].tot>b[j].tot)printf("%d ",a[i].num);
			else                 printf("%d ",b[j].num);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
