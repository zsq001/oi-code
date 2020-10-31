#include<bits/stdc++.h>
#define maxn 100010
#define inf 1<<29
using namespace std;
typedef long long ll;
struct TREE{
	int ma,mi;
	ll su;
}tree[maxn<<3];
int n,m,t,lazyA[maxn<<3],lazyS[maxn<<3],se[maxn<<3];
void pushup(int o){
	tree[o].su=tree[o<<1].su+tree[o<<1|1].su;
	tree[o].ma=max(tree[o<<1].ma,tree[o<<1|1].ma);
	tree[o].mi=min(tree[o<<1].mi,tree[o<<1|1].mi);
}
void build(int o,int l,int r){
	if(l==r){
		cin>>t;
		tree[o].su=tree[o].ma=tree[o].mi=t;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	if(se[o]){
		tree[o<<1].su=lazyS[o]*(mid-l+1);
		tree[o<<1|1].su=lazyS[o]*(r-mid);
		tree[o<<1].ma=tree[o<<1].mi=tree[o<<1|1].ma=tree[o<<1|1].mi=lazyS[o<<1]=lazyS[o<<1|1]=lazyS[o];
		se[o<<1]=se[o<<1|1]=1;
		lazyA[o<<1]=lazyA[o<<1|1]=lazyS[o]=se[o]=0;
	}
	if(!lazyA[o]) return;
	tree[o<<1].su+=lazyA[o]*(mid-l+1);
	tree[o<<1|1].su+=lazyA[o]*(r-mid);
	tree[o<<1].ma+=lazyA[o];
	tree[o<<1|1].ma+=lazyA[o];
	tree[o<<1].mi+=lazyA[o];
	tree[o<<1|1].mi+=lazyA[o];
	if(!se[o<<1]) lazyA[o<<1]+=lazyA[o];
	else lazyS[o<<1]+=lazyA[o];
	if(!se[o<<1|1]) lazyA[o<<1|1]+=lazyA[o];
	else lazyS[o<<1|1]+=lazyA[o];
	lazyA[o]=0;
}
void updateADD(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tree[o].su+=val*(r-l+1);
		tree[o].ma+=val;
		tree[o].mi+=val;
		if(se[o]) lazyS[o]+=val;
		else lazyA[o]+=val;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) updateADD(o<<1,l,mid,ql,qr,val);
	if(qr>mid) updateADD(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
void updateSET(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazyS[o]=tree[o].ma=tree[o].mi=val;
		tree[o].su=val*(r-l+1);
		lazyA[o]=0;
		se[o]=1;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) updateSET(o<<1,l,mid,ql,qr,val);
	if(qr>mid) updateSET(o<<1|1,mid+1,r,ql,qr,val);
	pushup(o);
}
ll querySUM(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o].su;
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	ll ret(0);
	if(ql<=mid) ret+=querySUM(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=querySUM(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int queryMAX(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o].ma;
	pushdown(o,l,r);
	int mid=(l+r)>>1,ret=-inf;
	if(ql<=mid) ret=max(ret,queryMAX(o<<1,l,mid,ql,qr));
	if(qr>mid) ret=max(ret,queryMAX(o<<1|1,mid+1,r,ql,qr));
	return ret;
}
int queryMIN(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o].mi;
	pushdown(o,l,r);
	int mid=(l+r)>>1,ret=inf;
	if(ql<=mid) ret=min(ret,queryMIN(o<<1,l,mid,ql,qr));
	if(qr>mid) ret=min(ret,queryMIN(o<<1|1,mid+1,r,ql,qr));
	return ret;
}
int main()
{
	int x,y,z;
	char s[10];
	cin>>n>>m;
	build(1,1,n);
	while(m--){
		cin>>s>>x>>y;
		if(s[2]=='d'){
			cin>>z;
			updateADD(1,1,n,x,y,z);
		}
		else if(s[2]=='t'){
			cin>>z;
			updateSET(1,1,n,x,y,z);
		}
		else if(s[2]=='m') cout<<querySUM(1,1,n,x,y)<<endl;
		else if(s[2]=='x') cout<<queryMAX(1,1,n,x,y)<<endl;
		else cout<<queryMIN(1,1,n,x,y)<<endl;
	}
	return 0;
}
