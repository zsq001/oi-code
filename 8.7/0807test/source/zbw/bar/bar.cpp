#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 1010
using namespace std;
int dp[maxn][maxn],v[maxn][maxn];
struct node{
	int a,b;
}vis[maxn];
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int nowx=1,nowy=1;
		for(int i=1;i<=2*n-2;i++){
			int a,b;
			scanf("%d%d",&vis[i].a,&vis[i].b);
		}
		for(int x=1;x<=n;x++){
			int tt;
			tt=1;
			memset(v,0,sizeof v);
			for(int y=1;y<=n;y++){
				dp[x][y]=max(dp[x-1][y],dp[x][y-1])+1;
				if(v[x][y]) dp[x][y]=0;
				//printf("dp[%d][%d]=%d\ntt=%d",x,y,dp[x][y],tt);
				v[vis[tt].a][vis[tt].b]++;
				tt++;
			}
		}
		if(dp[n][n]==2*n-1) puts("YES");
		else puts("No");
	}
}
