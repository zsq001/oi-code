#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 200005
#define mi mid=(l+r)>>1
#define ls o<<1
#define rs o<<1|1
int in(){
	int ret=0;char ch=getchar();bool ff=0;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=1;ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ff?-ret:ret;
}

int n;
ll tree[maxn<<2],a[maxn],lazy[maxn<<2];
bool vis[maxn<<2];

inline void pushup(int o){
	tree[o]=tree[ls]+tree[rs];
}

inline void pushdown(int o,int l,int r){
	if(!vis[o]) return ;
	int mi;
	lazy[ls]=lazy[o];
	lazy[rs]=lazy[o];
	tree[ls]=lazy[o]*(mid-l+1);
	tree[rs]=lazy[o]*(r-mid);
	vis[o]=1;
}

void build(int o,int l,int r){
	if(l==r){
		tree[o]=a[l+1]-a[l]<=0?0:a[l+1]-a[l];
		printf("%d %lld\n",o,tree[o]);
		return ;
	}
	int mi;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(o);
}

ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return tree[o];
	}
	int mi;
	ll ret=0;
	pushdown(o,l,r);
	if(ql<=mid) ret+=query(ls,l,mid,ql,qr);
	if(mid<qr) ret+=query(rs,mid+1,r,ql,qr);
	return ret;
}

void update(int o,int l,int r,int ql){
	if(l==r){
		tree[o]=a[l+1]-a[l]<=0?0:a[l+1]-a[l];
		return ;
	}
	int mi;
	if(ql<=mid) update(ls,l,mid,ql);
	else update(rs,mid+1,r,ql);
	pushup(o);
}

void update2(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tree[o]=(r-l+1)*val;
		lazy[o]=val;
		vis[o]=1;
		return ;
	}
	int mi;
	if(ql<=mid) update2(ls,l,mid,ql,qr,val);
	if(qr>mid) update2(rs,mid+1,r,ql,qr,val);
	pushup(o);
}

void Update(int l,int r,int x,int y){
	for(int i=l;i<=r;i++) a[i]=x+(i-l)*y;
	update(1,1,n-1,l-1);
	update(1,1,n-1,r);
	update2(1,1,n-1,l,r-1,y);
}

int Query(int l,int r){
	if(l>=r) return 0;
	return query(1,1,n-1,l,r-1);
}

int main(){
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	n=in();
	int m=in();
	for(int i=1;i<=n;i++){
		a[i]=1ll*in();
	}
	build(1,1,n-1);
	int op,l,r,x,y;
	while(m--){
		op=in();l=in();r=in();
		if(op==1){
			printf("%d\n",Query(l,r));
		}else{
			x=in();y=in();
			Update(l,r,x,y);
		}
	}
	return 0;
}
//6 5
//3 2 1 2 3 4
//1 1 5
//2 1 3 1 1
//1 1 5
//1 3 5
//1 1 6

