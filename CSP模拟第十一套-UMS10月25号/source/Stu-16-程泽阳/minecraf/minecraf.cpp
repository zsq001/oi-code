#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,m,ans;
int map[10010],mapp[10010];
struct node{
	int x,y,z;
}e[10010];

bool CMP(node q,node w)
{
	return q.x<w.x;
}

int abs(int a)
{
	if(a<0)return -a;
	return a;
}

void dfs()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&map[i]);
	}
	sort(map+1,map+1+n);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(map[j]-map[i] <= d){
				ans++;
			}
			else{
				break;
			}
		}
	}
	printf("%d",ans);
	return ;
}

void ddfs()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
	}
	sort(e+1,e+1+n,CMP);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(e[j].x-e[i].x > d){
				map[i]=j;
				break;
			}
		}
		map[i]=n;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=map[i];j++)
		{
			if((e[j].x-e[i].x)+abs(e[j].y-e[i].y) <= d){
				ans++;
			}
		}
	}
	printf("%d",ans);
}

void bfs()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	sort(e+1,e+1+n,CMP);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(e[j].x-e[i].x > d){
				map[i]=j;
				break;
			}
		}
		map[i]=n;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=map[i];j++)
		{
			if((e[j].x-e[i].x)+abs(e[j].y-e[i].y)+abs(e[j].z-e[i].z) <= d){
				ans++;
			}
		}
	}
	printf("%d",ans);
}

int main()
{
	int b;
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	scanf("%d%d%d%d",&b,&n,&d,&m);
	if(b==1)
	{
		dfs();
		return 0;
	}
	else if(b==2)
	{
		ddfs();
		return 0;
	}
	else if(b==3)
	{
		bfs();
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
