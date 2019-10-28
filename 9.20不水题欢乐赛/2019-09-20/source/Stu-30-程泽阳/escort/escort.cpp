#include<cstdio>
#include<string.h>
int map[1001][1001];
int n;

int min(int x,int y)
{
	if(x>y)return y;
	else return x;
}

int main()
{
	int m,t,s,X;
	int xx,xxx;
	int i,j,k,l,z;
	int ans=0;
	memset(map,0x3f,sizeof(map));
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&t,&s,&X);
	if(t==1){
		scanf("%d%d",&xx,&xxx);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&j,&k,&l,&z);
			map[j][k]=l;
			map[k][j]=z;
			map[i][i]=0;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
				}
			}
		}
		int ans=0;
		ans+=map[s][xx]+map[xx][xxx];
		printf("%d\n",ans);
	}
	else {
		for(i=1;i<=t;i++)
		{
			scanf("%d",&j);
			ans+=j;
		}
		for(i=1;i<=t;i++)
		{
			scanf("%d",&j);
			ans+=j;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&j,&k,&l,&m);
			ans+=j+k+l+m;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
