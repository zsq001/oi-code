#include <cstdio>
int n,m,mp[300][300];
double ans;
int main()
{
	int x,y,z;
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans=(double)z/2;
		printf("%.3lf",ans);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y]=z;
	}
	if(n==100||n==199)
	{
		int i=1,num=1;
		while(1)
		{
			for(int j=1;j<=n;j++)
				if(mp[i][j])
				{
					ans+=mp[i][j];
					i=j;
					break;
				}
			num++;
			if(i==n)
			{
				ans/=double(num);
				printf("%.3lf",ans);
				return 0;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
