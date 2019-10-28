#include<stdio.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define minn -0x7fffffff
int color[4000010],n,m,p,q;
void change(int l,int r,int x,int y,int v,int k)
{
	if(l>y||r<x)
	{
		return;
	}
	if(l>=x&&r<=y)
	{
		color[k]=v;
		return;
	}
	color[k]=-1;
	int mid=(l+r)/2;
	change(l,mid,x,y,v,k*2);
	change(mid+1,r,x,y,v,k*2+1);
}
int ask(int l,int r,int num,int k)
{
	if(l>num||r<num)
	{
		return minn;
	}
	if(color[k]!=-1)
	{
		return color[k];
	}
	int mid=(l+r)/2;
	return max(ask(l,mid,num,k*2),ask(mid+1,r,num,k*2+1));
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	int a,b,i;
	for(i=1;i<=m;i++)
	{
		a=(i*p+q)%n+1;
		b=(i*q+p)%n+1;
		change(1,n,min(a,b),max(a,b),i,1);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",ask(1,n,i,1));
	}
	return 0;
}
