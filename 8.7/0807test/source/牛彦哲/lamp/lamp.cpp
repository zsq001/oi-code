#include<stdio.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define maxn 0x7fffffff
int n,k,ans;
char a[100010][20],b[20];
void dfs(int step)
{
	int tmp=maxn,cos,i,j;
	if(step==k)
	{
		for(i=1;i<=n;i++)
		{
			cos=0;
			for(j=0;j<k;j++)
			{
				if(a[i][j]!=b[j])
				{
					cos++;
				}
			}
			tmp=min(tmp,cos);
		}
		ans=max(ans,tmp);
		return;
	}
	b[step]='0';
	dfs(step+1);
	b[step]='1';
	dfs(step+1);
}
int main()
{
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
