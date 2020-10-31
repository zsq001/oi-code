#include<cstdio>
#include<math.h>
#define maxn 100010
int tree[maxn<<2];
void pushup(int o){
	tree[o]=tree[o<<1]+tree[o<<1|1];
}

void build(int o,int l,int r){
	if(l==r){
		scanf("%d",&tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

void update(int o,int l,int r,int ql,int qr){
	if(l==r){
		tree[o]=1ll*sqrt(tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}

long long query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[o];
	int mid=(l+r)>>1;
	long long ret=0;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid)  ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int n,m,op,a,b;
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&a,&b);
		if(op==1){
			printf("%lld\n",query(1,1,n,a,b));
		}
		else{
			update(1,1,n,a,b);
		}
	}
	return 0;
}
