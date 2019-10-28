#include<cstdio>
int n,m,map[200010];
long long num=-2147483647;
bool mapp[200010];
int read()
{
	int date=0,w=1;
	char ch=0;
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){date=(date<<3)+(date<<1)+ch-'0';ch=getchar();}
	return date*w;
}
void dfs(int x,int d,long long maxx)
{
	int i,j,k;
	if(d>=m)
	{
		if(maxx > num)num=maxx;
		return;
	}
	if(x>n)return;
	if(x==1 && mapp[2]==0 && mapp[1]==0 && mapp[n]==0 || x==n && mapp[n-1]==0 && mapp[1]==0 && mapp[n]==0 || x>1 && x<n && mapp[x]==0 && mapp[x-1]==0 && mapp[x+1]==0)
	{
		mapp[x]=1;
		dfs(x+1,d+1,maxx+map[x]);
		mapp[x]=0;
	}
	dfs(x+1,d,maxx);
}
int main()
{
	int i;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		map[i]=read();
	}
	int nn;
	nn=(n/2)+1;
	if(m>=nn){
		printf("Error!");
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
