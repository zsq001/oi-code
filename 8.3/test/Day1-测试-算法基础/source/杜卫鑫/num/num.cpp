#include <stdio.h>
#include <algorithm>
using namespace std;
const int max1=1000005;
struct jv{
	int val,x,y;
}tong[max1];
int cnt,n,m,k;
bool cmp(jv x,jv y)
{
	return x.val<y.val;
}
void init_()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			tong[++cnt].val=i*j;
			tong[cnt].x=i;
			tong[cnt].y=j;
		}
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n>m)swap(n,m);
	if(n<=1000&&m<=1000)
	{
		init_();
		sort(tong+1,tong+cnt+1,cmp);
		for(int i=1;i<=max1;i++)
		{
			if(i==k)
			{
				printf("%d",tong[i].val);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
