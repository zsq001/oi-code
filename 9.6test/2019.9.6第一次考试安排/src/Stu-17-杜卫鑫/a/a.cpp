#include <stdio.h>
#include <algorithm>
using namespace std;
int f[10];
int main()
{
	int T,ans=0,n,x,minx=1000000;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		f[0]=f[1]=f[2]=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			f[x%3]++;
		}
		minx=min(f[1],f[2]);
		ans+=minx;
		f[1]-=minx;
		f[2]-=minx;
		ans+=f[0];
		if(f[1]>0)ans+=f[1]/3;
		if(f[2]>0)ans+=f[2]/3;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
