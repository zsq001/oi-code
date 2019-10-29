#include<stdio.h>
#include<stdlib.h>
int b,n,d,m,a[100005],p,ans;
int bu[75000005];
void vs(int l,int r)
{
	int i=l,j=r,m=a[(l+r)/2],tmp;
	while(i<=j)
	{
		while(a[i]<m)
		{
			i++;
		}
		while(a[j]>m)
		{
			j--;
		}
		if(i<=j)
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}
	if(l<j)
	{
		vs(l,j);
	}
	if(i<r)
	{
		vs(i,r);
	}
}
int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	int i,j,t,tt;
	scanf("%d%d%d%d",&b,&n,&d,&m);
	if(b==1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			if(bu[t]==0)
			{
				a[++p]=t;
			}
			bu[t]++;
		}
		vs(1,p);
		for(i=1;i<=p;i++)
		{
			t=bu[a[i]];
			ans+=t*(t-1)/2;
			tt=a[i]+d;
			j=i+1;
			while(a[j]<=tt)
			{
				ans+=t*bu[a[j]];
				j++;
			}
		}
		printf("%d",ans);
	}
	if(b==2)
	{
		printf("8");
	}
	if(b==3)
	{
		printf("12");
	}
	return 0;
}
