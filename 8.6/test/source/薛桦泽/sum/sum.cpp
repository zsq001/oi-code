#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 1000000007
using namespace std;

int n,m;
int num[100010],zone[100010]={0};

struct Query
{
	int id;
	int l,r,z;
}qu[100010];

int fib(int x)
{
	if(x==1) return 1;
	if(x==2) return 1;
	return (fib(x-1)%maxn+fib(x-2)%maxn)%maxn;
}

int main()
{
	freopen("sum.in","r",stdin);	
	freopen("sum.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=m;i++)	
	{
		scanf("%d",&qu[i].id);
		if(qu[i].id==1)
		{
			scanf("%d%d%d",&qu[i].l,&qu[i].r,&qu[i].z);
			for(int j=qu[i].l;j<=qu[i].r;j++)
				num[j]+=qu[i].z;
		}
		if(qu[i].id==2)
		{
			int ans=0;
			scanf("%d%d",&qu[i].l,&qu[i].r);
			for(int j=qu[i].l;j<=qu[i].r;j++)
			{
				ans+=fib(num[j]);
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
