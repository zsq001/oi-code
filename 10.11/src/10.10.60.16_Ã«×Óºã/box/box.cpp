#include<cstdio>
#include<cmath>
#define LL long long
const LL INF=214748364;
LL n,ans;
inline LL min(LL x,LL y)
{
	return x<y?x:y;
}
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%I64d",&n);
	LL k=(LL)pow((double)n,1.0/3.0);
	k+=2;
	ans=INF;
	for(LL i=1;i<=k;++i)
	{
		for(LL j=1;j<=sqrt(n/a)+1;++j)
		{
			LL t=n/(i*j);
			if(t*i*j!=n)continue;
			ans=min(ans,2*(i*j+i*t+t*j));
		}
	}
	printf("%I64d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
