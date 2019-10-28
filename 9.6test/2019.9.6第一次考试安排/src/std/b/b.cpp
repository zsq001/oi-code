#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=2e5+1;
const int mod=1e9+7;
int f[450][maxn];
int n;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	register int i,j,k,w;
	for(int i=0;i<=n;i++)
		f[1][i]=1;
	for(i=2;i*i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=((j-i>=0?f[i][j-i]:0)+(j-i>=0?f[i-1][j-i]:0))%mod;
	int ans=0;
	for(i=1;i*i<=n;i++)
		ans+=f[i][n];
	printf("%d\n",ans);
}
