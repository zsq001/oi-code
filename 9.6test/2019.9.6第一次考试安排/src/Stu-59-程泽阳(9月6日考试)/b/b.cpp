#include<cstdio>
#include<string.h>
bool mapp[50010];
int ans,n;

void dfs(int x,int y)
{
	int i,xx,yy;
	for(i=x+1;i<y;i++)
	{
		xx=i;
		yy=y-i;
		if(xx>=yy){
				return;
		}
		if(x+y < n)
		{
			if(xx<x || xx<y || yy<x || yy<y || n-i<i || xx>=yy){
				return;
			}
			
		}
		ans++;
		if(ans > 1000000007){
			ans=ans%1000000007;
		}
		dfs(xx,yy);
	}
}

int main()
{
	int i,nn;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	int x,y;
	for(i=1;i<n;i++)
	{
		x=i;
		y=n-i;
		if(x==y){
			break;
		}
		if(n-i < i || x>=y){
			break;
		}
		ans++;
		if(ans > 1000000007){
			ans=ans%1000000007;
		}
		dfs(x,y);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

