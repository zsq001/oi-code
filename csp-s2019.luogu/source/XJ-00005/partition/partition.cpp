#include<stdio.h>
#include<algorithm>
using namespace std;
int n,t,a[6000],b[6000],d,ans=2147483647;
void dfs(int nowd,int now)
{
	if(nowd==d)
	{
		b[d]=0;
		for(int i=now+1;i<=n;i++)
			b[d]+=a[i];
		int bi=b[1]*b[1];
		for(int i=2;i<=d;i++)
		{
			if(b[i]<b[i-1])return;
			bi+=b[i]*b[i];
		}
		if(bi<ans)ans=bi;
		return;
	}
	for(int i=now+1;i<=n-(d-nowd);i++)
	{
		
		for(int j=now+1;j<=i;j++)
			b[nowd]+=a[j];
		dfs(nowd+1,i);
		b[nowd]=0;
	}
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&t);
	if(t==0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n;i>=1;i--)
		{
			d=i;
			dfs(1,0);
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
