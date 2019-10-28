#include<stdio.h>
#include<algorithm>
#define mod 1000000007
using namespace std;

bool ifus[50010];
int n,ans=1;

void dfs(int m,int res,int stp)
{
	if(res<=0)
	{
		if(res==0) ans++;
		ans%=mod;
		return;
	}
	for(int i=m+1;i<n;i++)
	{
		if(res-i<0) return;
		if(!ifus[i]) 
		{
			ifus[i]=true;
			dfs(i,res-i,stp+1);
			ifus[i]=false;
		}
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	scanf("%d",&n);
	dfs(0,n,1);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
