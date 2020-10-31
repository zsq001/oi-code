#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 200010
using namespace std;
typedef long long ll;
int n,m,mod;
ll tree[maxn<<2],lazyp[maxn<<2],lazym[maxn<<2];
void pushup(int o){tree[o]=(tree[o<<1]+tree[o<<1|1])%mod;}
void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	tree[o<<1]=(tree[o<<1]*lazym[o]+lazyp[o]*(mid-l+1))%mod;
	tree[o<<1|1]=(tree[o<<1|1]*lazym[o]+lazyp[o]*(r-mid))%mod;
	lazyp[o<<1]=(lazyp[o<<1]*lazym[o]+lazyp[o])%mod;
	lazym[o<<1]=lazym[o<<1]*lazym[o]%mod;
	lazyp[o<<1|1]=(lazyp[o<<1|1]*lazym[o]+lazyp[o])%mod;
	lazym[o<<1|1]=lazym[o<<1|1]*lazym[o]%mod;
	lazyp[o]=0,lazym[o]=1;
}
void build(int o,int l,int r){
	lazym[o]=1;
	if(l==r){
		cin>>tree[o];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void updatep(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tree[o]=(tree[o]+(r-l+1)*val)%mod;
		lazyp[o]=(lazyp[o]+val)%mod;
		return; 
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(ql<=mid) updatep(o<<1,l,mid,ql,qr,val);
	if(qr>mid) updatep(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
void updatem(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tree[o]=tree[o]*val%mod;
		lazyp[o]=lazyp[o]*val%mod;
		lazym[o]=lazym[o]*val%mod;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(ql<=mid) updatem(o<<1,l,mid,ql,qr,val);
	if(qr>mid) updatem(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	ll ret(0);
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int main()
{
	int op,l,r,k;
	cin>>n>>m>>mod;
	build(1,1,n);
	while(m--){
		cin>>op>>l>>r;
		if(op==3) cout<<query(1,1,n,l,r)%mod<<endl;
		else{
			cin>>k;
			if(op==1) updatem(1,1,n,l,r,k);
			else updatep(1,1,n,l,r,k);
		}
	}	
    return 0;
}
