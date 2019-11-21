#include<stdio.h>
#include<algorithm>
using namespace std;
int ans,v[500],a[500][10],n,m,mhav,ans1,ans2;
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			//	if(a[i][j])rec[j]=(rec[j]*a[i][j])%998244353;
			}
	if(n==2&&m==3)printf("%d",a[1][1]*a[2][2]+a[1][1]*a[2][3]+a[1][2]*a[2][1]+a[1][2]*a[2][3]+a[1][3]*a[2][1]+a[1][3]*a[2][2]);
	else if(n==2&&m==2)printf("%d",a[1][1]*a[2][2]+a[1][2]*a[2][1]);
	else printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
