#include<bits/stdc++.h>
#define maxn 100010 
using namespace std;
typedef long long ll;
int n,m;
ll tree[maxn<<2];
void pushup(int o){
	tree[o]=tree[o<<1]+tree[o<<1|1];
}
void build(int o,int l,int r){
	if(l==r){
		cin>>tree[o];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr){
	if(l==r){
		tree[o]=1ll*sqrt(tree[o]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1;
	ll ret(0);
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int op,l,r;
    cin>>n;
    build(1,1,n);
    cin>>m;
	while(m--){
		cin>>op>>l>>r;
		if(l>r) swap(l,r); 
		if(op==0) update(1,1,n,l,r);
		else cout<<query(1,1,n,l,r)<<endl;
	}
    return 0;
}
