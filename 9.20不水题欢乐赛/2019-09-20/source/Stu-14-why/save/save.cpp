#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,ans,min=1000000;
int a[20];
int b[20];
int c[20][20];
bool t[20];
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	if(n==1)
	{
		printf("%d",a[1]+b[1]);
	}
	return 0;
}
