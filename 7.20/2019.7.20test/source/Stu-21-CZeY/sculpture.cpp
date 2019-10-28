#include<cstdio>
#include<math.h>
using namespace std;
long long a[1000010];
int main()
{
	int n,m,i,j,k;
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	int x,y,z;
	while(m--)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d",&y,&z);
			long long num=0;
			for(i=y;i<=z;i++)
			{
				num+=a[i];
			}
			printf("%lld\n",num);
		}
		else{
			scanf("%d%d",&y,&z);
			for(i=y;i<=z;i++)
			{
				a[i]=sqrt(a[i]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
