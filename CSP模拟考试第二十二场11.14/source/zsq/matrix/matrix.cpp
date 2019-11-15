#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,q;
//	cin>>n>>m>>q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
			for(int j=1;j<=m;j++)
			{
				a[j][y]=z;
			}
		else
			for(int j=1;j<=n;j++)
			{
				a[y][j]=z;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
