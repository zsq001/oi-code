#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int n,mod[5]={0},ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a,m;
			scanf("%d",&a);
			m=a%3;
			if(m) mod[m]++;
			else ans++;
		}
		int minn=min(mod[1],mod[2]);
		ans+=minn;
		mod[1]-=minn;
		if(mod[1]>0) ans+=mod[1]/3;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
