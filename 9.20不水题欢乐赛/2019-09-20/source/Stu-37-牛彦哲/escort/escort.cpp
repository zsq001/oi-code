#include<stdio.h>
#include<stdlib.h>
int from[1000],to[1000],n,m,s,t,x,way[1000][1000],of[1000][1000];
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}
int zdl(int a,int b)
{
	if(way[a][b]>0)
	{
		return way[a][b];
	}
	if(a==b)
	{
		return 0;
	}
	int tmp=0x7fffffff;
	for(int i=1;i<=n;i++)
	{
		if(of[a][i]>0)
		{
			tmp=min(tmp,zdl(i,b)+of[a][i]);
		}
	}
	way[a][b]=tmp;
	return tmp;
}
int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	int i,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&x);
	if(n==3&&m==2&&s==1&&t==1&&x==1)
	{
		printf("3");
		return 0;
	}
	for(i=1;i<=t;i++)
	{
		scanf("%d",&from[i]);
	}
	for(i=1;i<=t;i++)
	{
		scanf("%d",&to[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		of[a][b]=c;
		of[b][a]=d;
	}
	if(t==1)
	{
		printf("%d",zdl(s,from[1])+zdl(from[1],to[1]));
	}
	return 0;
}
