#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef pair<int,int> pr;
const int N=100050;
int n,h,b,e;
int c[N],cnt[N];

struct segt{

#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
pr s[(N<<2)+N];
void init(){memset(s,0,sizeof(s));}
void pushup(int p){s[p]=min(s[p<<1],s[p<<1|1]);}
void build(int l,int r,int p){
	if(l==r){
		s[p].first=c[l]; s[p].second=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(lson); build(rson);
	pushup(p);
}
pr query(int L,int R,int l,int r,int p){
	if(L<=l&&r<=R)return s[p];
	int mid=(l+r)>>1; pr res;
	res.first=res.second=N;
	if(L<=mid)res=min(res,query(L,R,lson));
	if(R>mid)res=min(res,query(L,R,rson));
	return res;
}

}T;

void work(int &now,int &nxt){
	if(now==nxt){
		++cnt[now];
		++nxt;
	}
	while(c[now]<c[nxt]&&nxt<=n&&nxt-now<h){
		++cnt[now];
		++nxt;
	}
	if(nxt-now==h&&c[now]<c[nxt]){
		pr res=T.query(now+1,nxt-1,1,n,1);
		now=res.second;
		work(now,nxt);
	}
}

void solve(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)read(c[i]);
	T.init(); T.build(1,n,1);
	int now=1,nxt=1;
	while(now<=n){
		work(now,nxt);
		now=nxt;
	}
	for(int i=b;i<=e;i++)printf("%d ",cnt[i]);puts("");
}

int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(scanf("%d%d%d%d",&n,&h,&b,&e)!=EOF) solve();
	return 0;
}
