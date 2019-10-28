#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int car[1010][1010]={0};
int ans[1010][1010];
int main()
{
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int lx,ly,rx,ry;
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		for(int i=lx;i<=rx;i++)
		{
			car[i][ly]+=1;
			car[i][ry+1]-=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i][j]=car[i][j]+ans[i][j-1];
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return  0;
}
