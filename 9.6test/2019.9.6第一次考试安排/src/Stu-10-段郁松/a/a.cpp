#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,t,p;
int a[1001];
int b=0,b1=0,ans=0,z=0,y=0,l=0;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,k,j,o;
	scanf("%d",&t);
	for(k=1;k<=t;++k)
	{
		scanf("%d",&n);
		p=n;
		for(i=1;i<=p;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]%3==0)
			{
				i--;
				p--;
				ans++;
				continue;
			}
		}
		sort(a,a+1+p);
		for(i=1;i<=p/2;++i)
		{
			for(j=p;j>=p/2;--j)
			{
				if((a[i]+a[j])%3==0&&a[i]!=0&&a[j]!=0)
				{
					a[j]=0;
					b=1;
					ans++;
					break;
				}
			}
			if(b==1)
			{
				a[i]=0;
				b=0;
				l--;
			}
		}
		z=i-1;//��i,��p+l 
		y=p+l;
		for(i=z;i<=(z+y)/2;++i)
		{
			for(j=y;j>=(z+y)/2;--j)
			{
				for(o=y-1;o>=z+1;--o)
				{
					if((a[i]+a[j]+a[o])%3==0&&a[i]!=0&&a[j]!=0&&a[o]!=0)
					{
						a[o]=0;
						b1=1;
						ans++;
						break;
					}
				}
				if(b1==1)
				{
					a[j]=0;
					break;
				}
			}
			if(b1==1)
			{
				a[i]=0;
				b1=0;
			}
		}
		printf("%d\n",ans);
		ans=0;//b=0,b1=0,ans=0,z=0,y=0,l=0
		b=0;
		b1=0;
		z=0;
		y=0;
		l=0;
		for(i=1;i<=n;++i)
		{
			a[i]=0;
		}
	}
	return 0;
}
