#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
#define ls o<<1
#define rs o<<1|1
#define mi mid=(l+r)>>1
int tree[1000010],lazy[1000010];
void pushup(int o){
	tree[o]=tree[ls]+tree[rs];
}
void pushdown(int o,int l,int r){
	if(!lazy[o])return;
	if(l==r){
		for(int i=1;i<=lazy[o];i++){
			tree[o]=sqrt(tree[o]);
		}
		return ;
	}
	for(int i=1;i<=lazy[o];i++){
			tree[o]=sqrt(tree[o]);
	}
	lazy[ls]+=lazy[o];
	lazy[rs]+=lazy[o];
	lazy[o]=0;
	int mi;
	pushdown(ls,r,mid);
	pushdown(rs,mid+1,l);
}
void build(int o,int l,int r){
	if(l==r){
		scanf("%d",&tree[o]);
		return ;
	}
	int mi;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		lazy[o]++;
		pushdown(o,l,r);
		return ;
	}
	int mi;
	pushdown(o,l,r);
	pushup(o);
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(qr>mid)update(rs,mid+1,r,ql,qr);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	pushdown(o,l,r);
	if(ql<=l&&r<=qr){
		return tree[o];
	}
	int mi,ret=0;
	if(ql<=mid)ret+=query(ls,l,mid,ql,qr);
	if(qr>mid)ret+=query(rs,mid+1,r,ql,qr);
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int n,q,op,x,y,m;
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			printf("%d\n",query(1,1,n,x,y));
		}
		else{
			scanf("%d%d",&x,&y);
			update(1,1,n,x,y);
		}
	}
	return 0;
}
/*8
1 2 3 4 5 6 7 8
3
0 2 4
0 6 7
1 3 8
*/
