#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	long long int V;
	scanf("%I64d",&V);
	long long int ans;
	int large=(int)pow(V,1.0/3);
	for(long long int i=1;i<=large;++i)
	{
		for(long long int j=1;j<=large;++j)
		{
			int a=V/(i*j);
			if(i*j*a!=V)continue;
			ans=min(ans,i*j+j*a+i*a);
		}
	}
	printf("%I64d",ans*2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
