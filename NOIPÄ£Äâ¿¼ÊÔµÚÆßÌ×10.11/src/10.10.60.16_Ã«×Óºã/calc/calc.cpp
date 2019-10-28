#include<cstdio>
#include<cstring>
#define LL long long
const LL MAXN=2010;
LL n,pre[MAXN],ans;
bool f[MAXN][MAXN];
char a[MAXN];
bool check(LL i,LL j)
{
	while(i<j)
	{
		if(a[i]!=a[j])return false;
		++i;--j;
	}
	return true;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	gets(a+1);
	n=strlen(a+1);
	for(LL i=1;i<=n;++i)
	{
		f[i][i]=true;
		++pre[i];
		for(LL j=i+1;j<=n;++j)
			if(a[i]==a[j])
				if(check(i,j))
				{
					f[i][j]=true;
					++pre[i];
				}
	}
	for(LL i=1;i<n;++i)
	{
		for(LL j=i;j<n;++j)
		{
			if(!f[i][j])continue;
			for(LL k=j+1;k<=n;++k)
			{
				ans+=pre[k];
			}
		}
	}
	printf("%I64d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
