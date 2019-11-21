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

namespace pt1{
	const int N=2005;
	int u[N],v[N];
	struct edge{int to,next;}e[N<<1];
	int head[N],tot;
	int rt,siz[N],tn,ans;
	
	void init(){
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(head,0,sizeof(head)); ans=tot=0;
	}
	void eclear(){
		memset(head,0,sizeof(head)); tot=0;
	}
	void add(int x,int y){
		e[++tot].to=y; e[tot].next=head[x]; head[x]=tot;
		e[++tot].to=x; e[tot].next=head[y]; head[y]=tot;
	}
	
	void dfs(int x){
		siz[x]=1;
		for(int i=head[x],y;i;i=e[i].next){
			if(siz[y=e[i].to])continue;
			dfs(y); siz[x]+=siz[y];
		}
	}
	void check(int x,int fa){
		bool suc=(tn-siz[x]<=(tn>>1));
		for(int i=head[x],y;i;i=e[i].next){
			if((y=e[i].to)==fa)continue;
			check(y,x);
			suc&=(siz[y]<=(tn>>1));
		}
		if(suc)ans+=x;
	}
	
	void solve(){
		init();
		for(int i=1;i<n;i++){
			read(u[i]); read(v[i]);
		}
		for(int d=1;d<n;d++){
			eclear();
			for(int i=1;i<d;i++)add(u[i],v[i]);
			for(int i=d+1;i<n;i++)add(u[i],v[i]);
			
			memset(siz,0,sizeof(siz));
			rt=u[d]; dfs(rt);
			tn=siz[rt]; check(rt,0);
			
			memset(siz,0,sizeof(siz));
			rt=v[d]; dfs(rt);
			tn=siz[rt]; check(rt,0);
		}
		printf("%d\n",ans);
		return ;
	}
}

namespace pt2{
	const int N=50505;
	struct edge{int to,next;}e[N<<1];
	int head[N],tot;
	int a[N],cnt;
	ll ans;
	bool vis[N];
	
	void init(){
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		ans=cnt=tot=0;
	}
	void add(int x,int y){
		e[++tot].to=y; e[tot].next=head[x]; head[x]=tot;
		e[++tot].to=x; e[tot].next=head[y]; head[y]=tot;
	}
	
	void dfs(int x){
		vis[x]=1; a[++cnt]=x;
		for(int i=head[x],y;i;i=e[i].next){
			if(vis[y=e[i].to])continue;
			dfs(y);
		}
	}
	ll cal(int l,int r){
		if((l+r)&1)return a[(l+r)/2]+a[(l+r)/2+1];
		else return a[(l+r)/2];
	}
	
	void solve(){
		init();
		for(int i=1,x,y;i<n;i++){
			read(x); read(y);
			add(x,y);
		}
		dfs(1);
		for(int i=1;i<n;i++){
			ans+=cal(1,i);
			ans+=cal(i+1,n);
		}
		printf("%lld\n",ans);
		return ;
	}
}

int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int T; read(T);
	while(T--){
		read(n);
		if(n<=1999)pt1::solve();
		else if(n==49991)pt2::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
