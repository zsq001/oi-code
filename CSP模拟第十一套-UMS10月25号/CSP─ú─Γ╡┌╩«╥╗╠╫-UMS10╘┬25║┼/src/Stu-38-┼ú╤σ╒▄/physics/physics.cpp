#include<stdio.h>
#include<stdlib.h>
struct node
{
	double a,t,v;
}s[100005],p[100005];
void vs(int l,int r)
{
	int i=l,j=r;
	double m=s[(l+r)/2].v;
	node tmp;
	while(i<=j)
	{
		while(s[i].v>m)
		{
			i++;
		}
		while(s[j].v<m)
		{
			j--;
		}
		if(i<=j)
		{
			tmp=s[i];
			s[i]=s[j];
			s[j]=tmp;
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
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	int n,i;
	double v0=0,s0=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&s[i].a,&s[i].t);
		s[i].v=s[i].a*s[i].t;
		s0+=(2*v0+s[i].v)*s[i].t/2;
		v0+=s[i].v;
	}
	vs(1,n);
	v0=0;
	for(i=1;i<=n;i++)
	{
		ans+=(2*v0+s[i].v)*s[i].t/2;
		v0+=s[i].v;
	}
	ans-=s0;
	printf("%.1lf",ans);
	return 0;
}
