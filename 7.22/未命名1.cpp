#include<iostream>
#define mmm 20000000
#define inf 2147483647
using namespace std;
typedef long long ll;
ll tree[mmm<<2],lazyp[mmm<<2],lazym[mmm<<2];
void pushup(int o)
{
	tree[o]=(tree[o<<1]+tree[o<<1|1]%mod);
}
void pushdown(int o,int l,int r)
{
	int mid=(mid)>>1;
	tree[o<<1]=(tree[o<<1]*lazym[o]+lazy[p]*(mid-l+1))%mod;
	tree[o<<1|1]=(tree[o<<1|1]*lazym[o]+lazyp[o]*(r-mid))%mod;
	lazyp[o<<1]=(lazyp[o<<1]*lazym[o]+lazyp[o])%mod;
	lazyp[o<<1|1]=(lazyp[o<<1|1]*lazym+lazy[o])%mod;
	lazym[o<<1]=lazym[o<<1]*lazym[o]%mod;
	lazym[o<<1|1]=lazym[o<<1|1]*lazym[o]%mod;
	lazyp[o]=0,lazym[o]=1;
}
ll query()
{
	if()
	return 
	pushdown()
	if() ret+=
	if() ret+=
	pushup();
	return ret;
	
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		cin>>tree[o];
		return ;
	}
	int mid=(l+r)/2;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1;r);
	pushup(o);
}
void updatep(int o,int l,int r,int ql,int qr,int val)
{
	if(ql<=l&&r<=qr)
	{
		tree[o]=(tree[o]+(r-l+1)*val)%mod;
		lazyp[o]=(lazyp[o]+val)%mod;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(ql<=mid)
	updatep(o<<1,l,mid,ql,qr,val);
	if(qr>mid)
	updatep(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
void updatem(int o,int l,int r,int ql,int qr,int val)
{
	if(ql<=l&&r<=qr)
	{
		tree[o]=tree[o]*val%mod;
		lazyp[o]=lazyp[o]*val%mod;
		lazym[o]=lazym[o]*val%mod;
		return ; 
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(ql<=mid)
	updatem(o<<1,l,mid,ql,qr,val);
	if(qr>mid)
	updatem(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
int main()
{
	
}
