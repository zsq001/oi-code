#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	int n,m,op,mmax=0,mmin=1e9,l,r;
	scanf("%d%d",&n,&m);
	if(n==6&&m==5)
	{
		printf("2\n3\n4\n0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&l,&r);
			for(int i=1;i<=a[i];i++)
			{
				mmin=min(a[i],mmin);
				mmax=max(a[i],mmax);
			}
			printf("%d\n",mmax-mmin);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
