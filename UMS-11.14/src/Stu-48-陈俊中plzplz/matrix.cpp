#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,m,q;
struct node
{
	int c,t;
}hang[10010],lie[10010];


int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1) 
		{
			hang[y].c=z;
			hang[y].t=i;
		}
		if(x==2) 
		{
			lie[y].c=z;
			lie[y].t=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(hang[i].t>lie[j].t)
			{
				printf("%d ",hang[i].c);
			}
			else
			{
				printf("%d ",lie[j].c);
			}
		}
		printf("\n");
	}
	return 0;
}
