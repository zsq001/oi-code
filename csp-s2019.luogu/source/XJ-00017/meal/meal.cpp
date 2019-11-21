#include<cstdio>
int n,m;
long long ans;
long long mo=998244353;
int map[1010][1010];
bool hang[1010];
int lie[1010];

int minn(int x,int y)
{
	if(x<y)return x;
	return y;
}

void dfs(int now,int num,long long anss,int ii)
{
	int i,j;
	if(num>=now)
	{
		ans+=anss;
		ans=ans%mo;
		return ;
	}
	for(i=ii+1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map[i][j] > 0 && hang[i]==false && lie[j] < now/2)
			{
				hang[i]=true;
				lie[j]++;
				dfs(now,num+1,anss%mo*map[i][j]%mo,i);
				hang[i]=false;
				lie[j]--;
			}
		}
	}
	return ;
}

int main()
{
	int i,j;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mi=minn(n,m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
		}	
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map[i][j] > 0){
				hang[i]=true;
				lie[j]++;
				for(int k=2;k<=mi;k++){
					dfs(k,1,map[i][j],i);
				}
				hang[i]=false;
				lie[j]--;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
