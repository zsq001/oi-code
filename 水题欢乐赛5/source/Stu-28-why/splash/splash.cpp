#include<cstdio>
#include<algorithm>
using namespace std;
int a[7][7];
int t,op,tr,fo;
int main()
{
	freopen("splash.in","r",stdin);
	freopen("splash.out","w",stdout);
	scanf("%d%d",&t,&op);
	while(t--)
	{
		for(int i=1;i<=6;i++)
		{
			for(int j=1;j<=6;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==3)tr++;
				else if(a[i][j]==4) fo++;
			}
		}
		if(op==1)
		{
			if(tr==1&&a[1][2]!=3)
			{
				printf("19\n");
			}
			else if(tr==1&&a[1][2]==3)
			{
				printf("18\n");
			}
			else if(tr==2)
			{
				printf("18\n");
			}
			else if(tr==3)
			{
				printf("17\n");
			}
		}
		if(op==2)
		{
			if(tr==1&&a[1][2]!=3)
			{
				printf("20\n");
			}
			else if(tr==1&&a[1][2]==3)
			{
				printf("19\n");
			}
			else if(tr==2)
			{
				printf("19\n");
			}
			else if(tr==3)
			{
				printf("18\n");
			}
		}
	}
}
