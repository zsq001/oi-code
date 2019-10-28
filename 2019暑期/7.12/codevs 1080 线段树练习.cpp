#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 100010
using namespace std;
int tree[maxn<<2],n,m;
void pushup(int o){tree[o]=tree[o<<1]+tree[o<<1|1];}
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
void add(int o,int l,int r,int pos,int k){
	if(l==r){
		tree[o]+=k;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) add(o<<1,l,mid,pos,k);
	else add(o<<1|1,mid+1,r,pos,k);
	pushup(o);
}
/*int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1;
	if(qr<=mid) return query(o<<1,l,mid,ql,qr);
	else if(ql>mid) return query(o<<1|1,mid+1,r,ql,qr);
	return query(o<<1,l,mid,ql,qr)+query(o<<1|1,mid+1,r,ql,qr);
}*/
int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1,ret(0);
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int main()
{
	int op,x,y;
	cin>>n;
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>op>>x>>y;
		if(op==1) add(1,1,n,x,y);
		else cout<<query(1,1,n,x,y)<<endl;
	}
	return 0;
}
