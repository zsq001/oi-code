#include<cstdio>
#include<algorithm>
#define inf 1<<29
using namespace std;
long long a,b,f[110][110],n,m,i,j,k;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			scanf("%d",&f[i][j]);
		}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",f[a][b]);
	}
	return 0;
}
