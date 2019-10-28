#include<stdio.h>
#include<math.h>
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout); 
	double v;
	scanf("%lf",&v);
	int a,b;
	long long ans=2147483648;
	double maxa=pow(v,(double)1/3);
	for(a=1;a<=maxa;++a)
	{
		int maxb=sqrt(v/a);
		for(b=a;b<=maxb;++b)
		{
			double c=v/a/b;
			if(c-(int)c)continue;
			long long s=2*(a*b+b*c+c*a);
			if(s<ans)ans=s;
		}
	}
	printf("%I64d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
