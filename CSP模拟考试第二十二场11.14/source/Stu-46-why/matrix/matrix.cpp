#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
int a[1010][1010][2];
int u[1010][1010];
struct node{
	int x,y,z,num;
}c[1000010];
int h[1010];
int l[1010];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
		if(c[i].x==1)
		{
			a[c[i].y][1][1]=c[i].z;
		}
		if(c[i].x==2)
		{
			a[1][c[i].y][2]=c[i].z;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][1][1]!=0)
		{
			for(int j=1;j<=m;j++)
			{	
				u[i][j]=a[i][1][1];
			}	
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[1][i][2]!=0)
		{
			for(int j=1;j<=n;j++)
			{	
				u[j][i]=a[1][i][2];
			}	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{	
			printf("%d ",u[i][j]);
		}	
		printf("\n");
	}
}
