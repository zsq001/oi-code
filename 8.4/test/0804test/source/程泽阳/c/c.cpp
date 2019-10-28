#include<cstdio>
typedef int int_;
#define long long int
int n,a[1000010];
int num=214748364;
void dfs(int x,int k,int maxx)
{
	int i;
	if(x==n && maxx<num)
	{
		num=maxx;
		return;
	}
	if(x>n)
	{
		return;
	}
	for(i=1;i<=k;i++)
	{
		if(a[i+x]>=a[x]){
			dfs(x+i,k,maxx+1);
		}
		else{
			dfs(x+i,k,maxx);
		}
	}
}
int_ main()
{
	int i,j,k;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int m;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&k);
		dfs(1,k,0);
		if(num==214748364)
		{
			printf("0\n");
		}
		else printf("%lld\n",num);
		num=214748364;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
