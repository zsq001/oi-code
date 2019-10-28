#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 200010
using namespace std;
ll tree[maxn<<2],lazy[maxn<<2];
void pushup(ll o){
	tree[o]=tree[o<<1]+tree[o<<1|1];
}
void pushdown(ll o,ll l,ll r){
	if(lazy[o]){
		while(lazy[o]--){
			tree[o<<1]=floor(sqrt(tree[o<<1]));
			tree[o<<1]=floor(sqrt(tree[o<<1]));
			lazy[o<<1]++;
			lazy[o<<1|1]++;
		}
	}
}
void build(ll o,ll l,ll r){
	if(l==r){
		scanf("%lld",&tree[o]);
		return;
	}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(ll o,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&qr>=r){
		tree[o]=floor(sqrt(tree[o]));
		lazy[o]++;
		return;
	}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}
ll query(ll o,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&qr>=r){
		return tree[o];
	}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	ll ret=0;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>r) ret+=query(o<<1|1,mid+1,r,ql,qr);
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	ll n,m;
	scanf("%lld",&n);
	build(1,1,n);
	scanf("%lld",&m);
	while(m--){
		ll op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1){
			printf("%lld\n",query(1,1,n,x,y));
		}
		else{
			update(1,1,n,x,y);
		}
	}
	return 0;
}
