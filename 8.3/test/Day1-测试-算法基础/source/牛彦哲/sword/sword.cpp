#include<stdio.h>
#include<stdlib.h>
int n,m,k,x,s,a[1000010],b[1000010],c[1000010],d[1000010];
void qst(int e[],int f[],int l,int r)//1 2 3
{
	int i=l,j=r,mid=e[(l+r)/2],t;
	while(i<j)
	{
		while(e[i]<mid)
		{
			i++;
		}
		while(e[j]>mid)
		{
			j--;
		}
		if(i<=j)
		{
			t=e[i];
			e[i]=e[j];
			e[j]=t;
			t=f[i];
			f[i]=f[j];
			f[j]=t;
			i++;
			j--;
		}
	}
	if(i<r)
	{
		qst(e,f,i,r);
	}
	if(l<j)
	{
		qst(e,f,l,j);
	}
}
int check(int p)
{
	int i,j,ask;
	for(i=1;i<=m;i++)
	{
		if(b[i]>s)
		{
			continue;
		}
		ask=n-p/a[i];
		if(ask<=0)
		{
			return 1;
		}
		for(j=k;j>0;j--)
		{
			if(c[j]<ask)
			{
				break;
			}
			if(c[j]>=ask&&b[i]+d[j]<=s)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	int l=1,r,mid,i;
	scanf("%d%d%d%d%d",&n,&m,&k,&x,&s);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&d[i]);
	}
	qst(a,b,1,m);
	qst(c,d,1,k);
	r=n*x;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d",r);
	return 0;
}
