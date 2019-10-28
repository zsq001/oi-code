#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long ll;
int tree[maxn<<2],lazy[maxn<<2],n,m;
void pushdown(int o,int l,int r){
	if(!lazy[o]) return;
	if(l==r){
		tree[o]+=lazy[o];
		lazy[o]=0;
		return;
	}
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
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
}
void update(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazy[o]+=val;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,val);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr,val); 
}
int query(int o,int l,int r,int pos){
	pushdown(o,l,r);
	if(l==r) return tree[o];
	int mid=(l+r)>>1;
	if(pos<=mid) return query(o<<1,l,mid,pos);
	return query(o<<1|1,mid+1,r,pos);
}
int main()
{
    int op,l,r,k,x;
    cin>>n;
    build(1,1,n);
    cin>>m;
    while(m--){
    	cin>>op;
    	if(op==1){
    		cin>>l>>r>>k;
    		update(1,1,n,l,r,k);
    	}
    	else{
    		cin>>x;
    		cout<<query(1,1,n,x)<<endl;
    	}
    }
    return 0;
}
