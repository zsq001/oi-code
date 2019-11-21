#include<stdio.h>
#include<algorithm>
#include<string.h>
#define mod 998244353
#define maxn 105
#define maxm 2005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
int tmp,cj[maxm],ans,a[maxn][maxm],n,m;
bool vis[maxn];
void dfs(int st,int k,int last){
	if(k-st>n-last) return;
	for(int i=last+1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=1;j<=m;j++){
			if(a[i][j]==0) continue;
			if(cj[j]<k/2){
				int re=tmp;
				tmp=(1ll*tmp*a[i][j])%mod;
				cj[j]++;
				vis[i]=1;
				if(st==k) {
					ans=(1ll*ans+tmp)%mod;
				}
				if(st<k)
				dfs(st+1,k,i);
				cj[j]--;
				vis[i]=0;
				tmp=re;
			}
		}
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(a[i][j]);
	for(int k=2;k<=n;k++){
		tmp=1;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=m;i++) cj[i]=0;
		dfs(1,k,0);		
	}
	printf("%d",ans);
	return 0;
}

