#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x[1001],y[1001];
bool flag=0,vis[1010][1010],f[1010][1010];
int tx[4]={1,0,-1,0},ty[4]={0,1,0,-1};
void dfs(int xnow,int ynow,int deep){
	if(xnow==n&&ynow==n){
		flag=1;
		return ;
	}
	vis[xnow][ynow]=1;
	f[x[deep]][y[deep]]=1;
	for(int i=0;i<4;i++){
		int xx=xnow+tx[i],yy=ynow+ty[i];
		if(xx>n||xx<1||yy>n||yy<1||vis[xx][yy]||f[xx][yy])continue;
		dfs(xx,yy,deep+1);
		if(flag)return ;
	}
	f[x[deep+1]][y[deep+1]]=0;
}
int main(){
	int T;
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0;
		scanf("%d",&n);
		if(n<=700){
			memset(f,0,sizeof(f));
			memset(vis,0,sizeof(vis));
			n=2*n-2;
			for(int i=1;i<=n;i++){
				scanf("%d%d",&x[i],&y[i]);
			}
			dfs(1,1,0);
			if(flag)puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}
