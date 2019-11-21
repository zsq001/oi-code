#include<stdio.h>
#include<string.h>
using namespace std;

int a[2010],bian[2010][2010],b[2010];

int main()
{
	int n,m,c;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&m);
	for(int ii=1;ii<=n;ii++)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n+2;i++)memset(bian[i],0,sizeof(bian[i]));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			a[b[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			int r;
			while(bian[b[i]][b[i]-1]==0)
			{
				r=b[a[b[i]-1]];
				b[a[b[i]-1]]=b[i];
				b[i]=r;
				for(int i=1;i<=n;i++)
		        {
				 a[b[i]]=i;
				}
				bian[b[i]][b[i]-1]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[b[i]]=i;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
