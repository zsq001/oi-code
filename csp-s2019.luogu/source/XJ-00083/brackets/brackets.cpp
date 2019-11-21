#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef long long ll;

int n;
int fa[500055];
char s[500055];
bool ch=1;

namespace pt1{
	const int N=2005;
	struct edge{int to,next;}e[N];
	int head[N],tot;
	int t[N],sum[N];
	int cnt[N][N],ans;
	
	void adde(int x,int y){
		e[++tot].to=y; e[tot].next=head[x]; head[x]=tot;
	}
	
	void dfs(int x,int dep,int now,int o){
		sum[dep]=sum[dep-1]+t[x];
		bool f=1;
		if(sum[dep]<0){
			sum[dep]=0; f=0; ++o;
			memset(cnt[o],0,sizeof(cnt[o]));
			cnt[o][0]=1;
		}
		if(f){
			if(s[x]==')')now+=cnt[o][sum[dep]];
			++cnt[o][sum[dep]];
		}
		ans=ans^(x*now);
//		printf("%d %d\n",x,now);
		for(int i=head[x],y;i;i=e[i].next){
			dfs(y=e[i].to,dep+1,now,o);
		}
		if(f)--cnt[o][sum[dep]];
	}
	void solve(){
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)t[i]=(s[i]=='(')?1:-1;
		for(int i=2;i<=n;i++){
			read(fa[i]); adde(fa[i],i);
		}
		cnt[0][0]=1; dfs(1,1,0,0);
		printf("%d\n",ans);	
	}
};
namespace pt2{
	const int N=500055;
	int sum[N];
	int cnt[N],t[N];
	ll ans=0;
	void solve(){
		int maxs=0;
		ll now=0;
		for(int i=1;i<=n;i++)t[i]=(s[i]=='(')?1:-1;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+t[i];
			maxs=max(maxs,sum[i]);
			if(sum[i]<0){
				sum[i]=0;
				for(int j=1;j<=maxs;j++)cnt[j]=0;
				cnt[0]=1; maxs=0;
			}
			else {
				if(s[i]==')')now+=cnt[sum[i]];
				++cnt[sum[i]];
			}
			ans^=(now*1ll*i);
//			printf("%d %lld\n",i,now);
		}
		printf("%lld\n",ans);
		return ;
	}
}

int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	read(n);
	if(n<=2000){pt1::solve();return 0;}
	scanf("%s",s+1);
	for(int i=2;i<n;i++)read(fa[i]),ch&=(fa[i]==i-1);
	if(ch)pt2::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
