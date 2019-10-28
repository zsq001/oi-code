#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1010][1010];
int n,m;
int d[1010][1010];
int main()
{
	int x1,x2,y1,y2;
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<=x2;j++)
		{
			d[j][y1]++;
			d[j][y2+1]--;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=a[i][j-1]+d[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
