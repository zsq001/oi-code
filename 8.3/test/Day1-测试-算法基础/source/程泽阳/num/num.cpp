#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100000010];
long long num;
int ans=0;

bool CMP(int x,int y)
{
	return x<y;
}

int main()
{
	int n,m;
	long long i,j,k;
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			num=i*j;
			a[++ans]=num;
		}
	}
	sort(a+1,a+1+ans,CMP);
	printf("%lld",a[k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
