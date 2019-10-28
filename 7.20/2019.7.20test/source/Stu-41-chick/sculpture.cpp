#include<bits/stdc++.h>
using  namespace std;
long long tree[400003],lazy[400004];
void pushup(int o){
	tree[o]=tree[o<<1]+tree[o<<1|1];
} 
void pushdown(int o,int l,int r){
	if(!lazy[o]) return;
	int mid=(l+r)>>1;
	tree[o<<1]+=(mid-l+1)*lazy[o];
	tree[o<<1|1]+=(r-mid)*lazy[o];
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
	lazy[o]=0;
}
void update(int o,int l,int r,int ql,int qr){
	if(l==r&&l>=ql&&l<=qr){
		tree[o]=floor(sqrt(tree[o]));
		return;
	}
	int mid=(l+r)>>1;
	update(o<<1,l,mid,ql,qr);
	update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}
long long query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1,ret=0;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
void build(int o,int l,int r){
	if(l==r) {
		scanf("%lld",&tree[o]);
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int n;
	scanf("%d",&n);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int num,a,b;
		scanf("%d%d%d",&num,&a,&b);
		if(num==0){
			update(1,1,n,a,b);
		}
		else{
			printf("%lld\n",query(1,1,n,a,b));
		}
	}
	return 0;
}
