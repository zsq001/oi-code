#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int n,m,tree[maxn<<2][8],lazy[maxn<<2],tmp[8],t;
void pushup(int o){
	for(int i=0;i<7;++i)
		tree[o][i]=tree[o<<1][i]+tree[o<<1|1][i];
}
void pushdown(int o,int l,int r){
	if(!lazy[o]) return;
	for(int i=0;i<7;++i)
		tmp[(i+lazy[o])%7]=tree[o<<1][i];
	for(int i=0;i<7;++i)
		tree[o<<1][i]=tmp[i];
	for(int i=0;i<7;++i)
		tmp[(i+lazy[o])%7]=tree[o<<1|1][i];
	for(int i=0;i<7;++i)
		tree[o<<1|1][i]=tmp[i];
	lazy[o<<1]=(lazy[o<<1]+lazy[o])%7;
	lazy[o<<1|1]=(lazy[o<<1|1]+lazy[o])%7;
	lazy[o]=0;
}
void build(int o,int l,int r){
	if(l==r){
		cin>>t;
		tree[o][t%7]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazy[o]=(lazy[o]+val)%7;
		for(int i=0;i<7;++i)
			tmp[(i+val)%7]=tree[o][i];
		for(int i=0;i<7;++i)
			tree[o][i]=tmp[i];
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,val);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o][0];
	pushdown(o,l,r);
	int mid=(l+r)>>1,ret=0;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret; 
}
int main()
{
	int x,y,z;
	char s[10];
	cin>>n;
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>s>>x>>y;
		if(s[0]=='a'){
			cin>>z;
			update(1,1,n,x,y,z%7);
		}
		else cout<<query(1,1,n,x,y)<<endl;
	}
	return 0;
}
