#include <stdio.h>
#include <algorithm>
using namespace std;
int prin[1000000];
int main()
{
	int n,m,p,q;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=m;i++)
	{
		int l=(i*p+q)%n+1,r=(i*q+p)%n+1;
		if(l>r)swap(l,r);
		for(int j=l;j<=r;j++)
				prin[j]=i;		
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",prin[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
		
