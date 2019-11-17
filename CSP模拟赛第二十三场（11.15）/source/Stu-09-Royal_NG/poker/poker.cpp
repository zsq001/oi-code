#include<stdio.h>
#include<algorithm>
using namespace std;
int tot,c[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	tot=1;
	while(m>0)
	{
		int dx=c[tot+1]-c[tot];
		if(m>dx*tot&&tot!=n)
		{
			m-=dx*tot;
			c[tot]+=dx;
			tot++;
		}
		else
		{
			printf("%d",c[tot]+m/tot);
			m=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
