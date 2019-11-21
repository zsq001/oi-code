#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,a[50001],ans;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(!m)
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int k=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i+1])
			{
				if(a[i+2]+a[i+1]>=a[i])
				{
					if(a[i+2]<=a[i])
					{
						a[i+2]+=a[i+1];
						a[i+1]=0;
					}
					else
					{
						a[i+1]+=a[i];
						a[i]=0;
					}
					
				}
				else
				{
					a[i]+=a[i+1];
					a[i+1]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[i]*=a[i];
			ans+=a[i];
		}
		printf("%d",ans);
	}
	return 0;
}
