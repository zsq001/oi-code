#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
int n;

struct Matrix{
	ll v[2][2];
	Matrix(){memset(v,0,sizeof(v));}
}a,ans;

Matrix operator*(Matrix x,Matrix y){
	Matrix res;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	for(int k=0;k<2;k++)
		(res.v[i][j]+=(x.v[i][k]*y.v[k][j]%mod))%=mod;
	return res;
}

int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n); n++;
	ans.v[0][0]=1;
	a.v[0][0]=a.v[0][1]=a.v[1][1]=1;
	a.v[1][0]=2;
	for(int i=n;i;i>>=1,a=a*a)
		if(i&1) ans=ans*a;
	printf("%lld\n",ans.v[0][0]);
	return 0;
}
