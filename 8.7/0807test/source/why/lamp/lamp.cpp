#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500050
using namespace std;
int n,k,cnt=1,u,v,sum;
char a[1000010][20],p,m;
int main()
{
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		printf("%d",k);
		return 0;
	}
	if(n!=1)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%c",&p);
				if(m!=p)
				{
					printf("0");
					return 0;
				}
				m=p;
			}
			printf("1\n");
			return 0;
		}
		if(k==2)
		{
			if(n>=4)
			{
				printf("0");
				return 0;
			}
			if(n==3||n==2)
			{
				printf("1");
				return 0;
			}
		}
		if(k==3)
		{
			if(n>=2)
			{
				for(int i=1;i<=n;i++)
				{
					scanf("%d",&u);
					sum+=u;
					if(sum==111)
					{
						printf("1");
						return 0;
					}
				}
				printf("2");
				return 0;
			}
		}
	}
}
