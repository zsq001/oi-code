#include<cstdio>
int map[500010];
long long ans;
int n,m;

int abc(int x,int y){
	int z;
	z=x-y;
	if(z<0)return -z;
	return z;
}

void dfs(int now,int last,long long anss)
{
	if(now>n && ans==0){
		ans=anss;
		return ;
	}
	if(now>n && ans!=0){
		if(ans > anss){
			ans=anss;
		}
		return ;
	}
	if(now==n){
		dfs(now+1,last,anss+(last+map[now])*(last+map[now]));
	}
	if(map[now]==map[now+1]){
		dfs(now+1,map[now+1],anss+map[now+1]*map[now+1]);
	}
	if(last<=map[now] && map[now] < map[now+1]){
		dfs(now+1,map[now],anss+(map[now])*(map[now]) );
	}
	if(map[now] > map[now+1]){
		dfs(now+1,map[now],anss+(map[now])*(map[now]));
		dfs(now+2,map[now]+map[now+1],anss+(map[now]+map[now+1])*(map[now]+map[now+1]) );
	}
	if(last > map[now]){
		int xx=map[now];
		while(last > xx){
			now++;
			xx+=map[now];
		}
		dfs(now+1,xx,anss+(xx)*(xx));
	}
	return ;
}//partition

int main()
{
	int i,j;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&map[i]);
	}	
	dfs(1,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
