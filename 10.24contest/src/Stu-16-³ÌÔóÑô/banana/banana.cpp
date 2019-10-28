#include<cstdio>
#include<algorithm>
using namespace std;
int map[10010],k,n;
bool mapp[10010];
int mod=1000000007;
int ans=0;
void dfs(int now,int x)
{
	int i,j;
	if(now==k){
		ans++;
		ans=ans%mod;
		return ;
	}
	if(now>k){
		return ;
	}
	for(i=x;i<=n;i++)
	{
		if(now*map[i] > k){
			return ;
		}
		if(mapp[i]==true){
			continue;
		}
		if(now*map[i] <= k){
			mapp[i]=true;
			dfs(now*map[i],i);
			mapp[i]=false;
		}
	}
}

int main()
{
	int d,i,j;
	freopen("banana.in","r",stdin);
	freopen("banana.out","w",stdout);
	scanf("%d",&d);
	for(i=1;i<=d;i++)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&map[j]);
		}
		sort(map+1,map+1+n);
		dfs(1,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
