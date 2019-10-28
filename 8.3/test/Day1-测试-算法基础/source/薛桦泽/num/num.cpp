#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int m,n,k,tot=0;
long long num[1234567];
int cnt[1234567];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!cnt[i*j]) num[++tot]=i*j;
			cnt[i*j]++;
		}
	}
	int tem=0;
	sort(num+1,num+1+m*n,cmp);
	for(int i=1;i<=m*n;i++)
	{
		tem+=cnt[num[i]];
		if(tem>=m*n-k+1)
		{
			printf("%lld",num[i]);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
