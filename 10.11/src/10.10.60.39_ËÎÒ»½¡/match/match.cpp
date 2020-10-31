#include<cstdio>
#define ll long long
ll l[100005],r[100005],n,m,x,y,a,b,ans=0,flag=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i,j;
	ll x;
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a);
		l[i]=a-x;r[i]=a+y;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%I64d",&b);
		for(j=flag+1;j<=n;j++)
		{
			if(l[j]<=b&&r[j]>=b){
				flag=j;
				ans++;
				break;
			}
		}
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
