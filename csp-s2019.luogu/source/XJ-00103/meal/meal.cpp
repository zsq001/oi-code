#include<bits/stdc++.h>
#define LL long long
#define MOD 998244353
using namespace std;
template <class T> void read(T &x)
{
	x=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
}
LL ans;
int n,m;
LL F[101][2010];
int vis[2010],VIS[2010];
bool check(int now){
	for(int i=1;i<=m;++i)
	{
		if(vis[i]<=(now>>1)) continue;
		return false;
	}
	return true;
}
void dfs(LL tmp,int cnt,int k){
	if(cnt>=2){
		if(check(cnt)) {
			ans=(ans+tmp)%MOD;
		}
	}
	for(int i=k+1;i<=n;++i)
	{
		if(!VIS[i])
		{
			VIS[i]=1;
			for(int j=1;j<=m;++j)
			{
				vis[j]++;
				dfs((tmp*F[i][j])%MOD,cnt+1,i);
				vis[j]--;
			}
			VIS[i]=0;
		}
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(F[i][j]);
	dfs(1,0,0);
	printf("%lld",ans%MOD);
	return 0;
}
