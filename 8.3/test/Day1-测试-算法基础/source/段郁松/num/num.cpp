#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int x,y,k,ans=0;
long long int b[500005*4];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&x,&y,&k);
	for(i=1;i<=x;++i)
	{
		for(j=1;j<=y;++j)
		{
			b[++ans]=i*j;
		}
	}
	sort(b,b+x*y);
	printf("%lld",b[k]);
	return 0;
}
