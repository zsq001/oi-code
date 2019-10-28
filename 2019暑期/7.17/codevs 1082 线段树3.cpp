#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 200010
using namespace std;
typedef long long ll;
ll tree[maxn<<2],lazy[maxn<<2];
void pushup(int o){tree[o]=tree[o<<1]+tree[o<<1|1];}
void pushdown(int o,int l,int r){
	if(!lazy[o]) return;
	int mid=(l+r)>>1;
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
	tree[o<<1]+=lazy[o]*(mid-l+1);
	tree[o<<1|1]+=lazy[o]*(r-mid);
	lazy[o]=0;
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
void update(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazy[o]+=val;
		tree[o]+=val*(r-l+1);
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,val);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	pushdown(o,l,r);
	ll mid=(l+r)>>1,ret(0);
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int main()
{
    int n,q,op,x,y,z;
    cin>>n;
    build(1,1,n);
    cin>>q;
    while(q--){
    	cin>>op;
    	if(op==1){
    		cin>>x>>y>>z;
    		update(1,1,n,x,y,z);
    	}
    	else{
    		cin>>x>>y;
    		cout<<query(1,1,n,x,y)<<endl;
    	}
    }
    return 0;
}
