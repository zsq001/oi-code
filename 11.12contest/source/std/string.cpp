#include<cstdio>
#define MN 200000
#define MOD 1000000007
char s[MN+5];
int f[MN+5],p[MN+5];
int F(int l,int r){return (f[r]+MOD-1LL*f[l-1]*p[r-l+1]%MOD)%MOD;}
int cal(int i,int x)
{
	int l=1,r=i,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(F(1,mid)!=F(x,x+mid-1))res=mid,r=mid-1;else l=mid+1;
	}
	return res;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		if(n<2){puts("0");continue;}
		for(p[0]=i=1;i<=n;++i)f[i]=(37LL*f[i-1]+s[i])%MOD,p[i]=37LL*p[i-1]%MOD;
		for(i=1;i<n;++i)
		{
			for(j=1;j+i-1<=n;j+=i)if(F(1,i)!=F(j,j+i-1))break;
			if(j+i-1<=n)
			{
				int res=cal(i,j);
				if(j+i>n){if(F(res,i-1)==F(j+res,j+i-1))break;}
				if(F(res,i)==F(j+res,j+i))
				{
					while((j+=i)+i<=n)if(F(1,i)!=F(j+1,j+i))break;
					if(j+i>n&&F(1,n-j)==F(j+1,n))break;
				}
			}
			else
			{
				if(F(1,n-j+1)==F(j,n))break;
				int res=cal(n-j+1,j);
				if(F(res,n-j)==F(j+res,n))break;
			}
			if(i+i+1<=n)
			{
				if(F(1,i)!=F(i+2,i+i+1))
				{
					int res=cal(i,i+2);
					if(F(res+1,i+1)!=F(i+res+1,i+i+1))continue;
				}
				for(j=i+i+1;j+i<=n;j+=i)if(F(i+2,i+i+1)!=F(j+1,j+i))break;
				if(j+i>n&&F(i+2,i+1+n-j)==F(j+1,n))break;
			}
			else
			{
				if(F(1,n-i-1)==F(i+2,n))break;
				int res=cal(n-i-1,i+2);
				if(F(res+1,n-i)==F(i+1+res,n))break;
			}
		}
		printf("%d\n",i);
	}
}
