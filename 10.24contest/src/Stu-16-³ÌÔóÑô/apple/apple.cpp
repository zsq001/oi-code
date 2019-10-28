#include<cstdio>
#include<string.h>
int map[1010][1010];
int ans=0;

int max(int x,int y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int n,k;
	int i,j,l;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d%d",&n,&k);
	int x;
	memset(map,-1,sizeof(map));
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		map[x][i]=1;
		map[i][x]=1;
	}
	for(l=0;l<n;l++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				map[i][j]=max(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	while(ans < n)
	{
		printf("%d\n",k);
		int maxx=-2147483;
		int x;
		for(i=0;i<n;i++)
		{
			if(map[k][i]>maxx){
				maxx=map[k][i];
				x=i;
			}
		}
		k=x;
		ans+=maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
