#include<cstdio>
using namespace std;
int n,m,a[110][2100],l,b[2100],x;
void enterprise(int k)
{
	if(k>n)
		return ;
	for(int i=1;i<=m;i++)
	{
		if(a[k][i]==1)
		{
			b[i]++;
			l++;
			if(l>1)
			{
				int y=0;
				for(int i=1;i<=m;i++)
				if(b[i]>l/2)
				{
					y=1;
					break;
				}
				if(y==0)
					x++;
			}
			enterprise(k+1);
			l--;
			b[i]--;
		}
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	enterprise(1);
	printf("%d",x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
