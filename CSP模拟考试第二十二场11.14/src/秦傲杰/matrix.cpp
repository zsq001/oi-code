#include<stdio.h>
#define N 1010
struct node{
				int z,t;	
		   }x[N],y[N];
int k,b,c,n,m,q;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&k,&b,&c);
		if(k==1){
					x[b].z=c;
					x[b].t=i;
				}
		else
		{
			y[b].z=c;
			y[b].t=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int t1=x[i].t;
		for(int j=1;j<=m;j++)
		{
			if(t1>y[j].t)printf("%d ",x[i].z);
			else         printf("%d ",y[j].z);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
