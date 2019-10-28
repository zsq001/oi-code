#include<cstdio>
#include<cmath>
long long a[5],ans=9999999999ll,l,r,mid,i,v,k,j,m;
long long min(long long x,long long y){return x<y?x:y;}
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%I64d",&v);
	l=1,r=v+1;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(mid*mid>v)r=mid;
		else {
			if(mid*mid*mid>v)r=mid;
			else l=mid;
		}
	}
	for(i=1;i<=r;i++)
	{
		if(v%i==0)
		{
			k=v/i;
			for(j=sqrt(k);j>=1;j--)
			{
				if(k%j==0)
				{
					m=k/j;
					ans=min(ans,(i*j+m*i+m*j)<<1);
					break;
				}
			}
		}
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
