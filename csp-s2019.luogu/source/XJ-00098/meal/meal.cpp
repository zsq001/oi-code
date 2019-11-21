#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

#define ll long long
#define maxn 105
#define maxm 2005

int read(){
	int ret=0;char ch=getchar();//bool ff=0;
	while(ch<'0'||ch>'9') {ch=getchar();}
	while(ch>='0'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

const int mod=998244353;
int a[maxn][maxm],n,m,maxcho;
int usel[maxm];

ll dfs(int need,int nowhang){
	if(nowhang==n+1) return 0;
	ll ret=0ll;
	for(int j=nowhang;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(usel[i]<maxcho){
				usel[i]++;
				if(need==1){
					if(a[j][i]) ret=(ret+1ll*a[j][i])%mod;
				}
				else {
					int x=dfs(need-1,j+1);
					ret=(ret+1ll*x*a[j][i])%mod;
				}
				usel[i]--;
			}
		}	
	}
	return ret;
}



int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	
	ll ans=0;
	for(int i=2;i<=n;i++){
		maxcho=i/2;
		ans=(ans+dfs(i,1))%mod;
	}
	printf("%lld",ans);
	return 0;
}
//5 5
//1 0 0 1 1
//0 1 0 1 0
//1 1 1 1 0
//1 0 1 0 1
//0 1 1 0 1

