#include<cstdio>
#include<cmath>
int main()
{
	freopen("box.in","r",stdin),freopen("box.out","w",stdout);
	long long v,s=1e15;
	scanf("%I64d",&v);
	for(long long i=1;i*i*i<=v;i++)
		if(v%i==0)
			for(long long j=1;j<=sqrt(v/i);j++)
				if((v/i)%j==0&&s>(j*i+v/i+v/j)<<1)
					s=(j*i+v/i+v/j)<<1;
	printf("%I64d",s);
	fclose(stdin),fclose(stdout);
	return 0;
}
// i j v/(i*j) i*j+v/(i*j)*i+v/(i*j)*
