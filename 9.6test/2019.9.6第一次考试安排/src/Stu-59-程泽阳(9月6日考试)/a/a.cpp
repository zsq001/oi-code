#include<cstdio>
long long a;
long long ans=0;
long long aa[10];

int min(int x,int y)
{
	if(x>y)return y;
	else return x;
}

int main()
{
	int t,n,i;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		aa[1]=0;
		aa[2]=0;
		aa[0]=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			aa[a%3]++;
		}
		long long mi;
		mi=min(aa[1],aa[2]);
		ans=mi;
		ans+=aa[0];
		aa[1]-=mi;
		aa[2]-=mi;
		ans+=aa[1]/3;
		ans+=aa[2]/3;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
