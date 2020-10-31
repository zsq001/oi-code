#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

struct node{
	int next,to;
}e[200050];

int n,m,cnt,tot;
int head[100050],deep[100050],fa[100050],hv[100050],ht[100050];
int tree[400050],lazy[400050],val[100050],dfn[100050],anti[100050];
int top[100050];

void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}

int dfs1(int o,int f){
	fa[o]=f;
	deep[o]=deep[f]+1;
	hv[o]=o;
	int hvest=0;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==f) continue;
		int weit=dfs1(x,o);
		if(weit > hvest){
			hv[o]=x;
			hvest=weit;
		}
	}
	return hvest+1;
}

int dfs2(int o,int topp){
	dfn[o]=++cnt;
	anti[cnt]=o;
	top[o]=topp;
	ht[o]=dfn[o];
	if(hv[o]==o) return dfn[o];
	ht[o]=max(dfs2(hv[o],topp),ht[o]);
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa[o]) continue;
		if(x==hv[o]) continue;
		ht[o]=max(dfs2(x,x),ht[o]);
	}
	return ht[o];
}

void pushup(int o){
	tree[o]=tree[o<<1]+tree[o<<1|1];
	return;
}

void pushdown(int o,int l,int r){
	if(lazy[o]==0) return ;
	int mid=(l+r)>>1;
	tree[o<<1]+=(mid-l+1)*lazy[o];
	tree[o<<1|1]+=(r-mid)*lazy[o];
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
	lazy[o]=0;
	return ;	
}


void build(int o,int l,int r){
	lazy[o]=0;
	if(l>=r){
		tree[o]=val[anti[l]];
		return ;
	}
	int mid=(r+l)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

void add(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l && r<=qr){
		tree[o]+=(l-r+1)*x;
		lazy[o]+=x;
	    return ;
	}
	int mid=(r+l)>>1;
	pushdown(o,l,r);
	if(ql<=mid) add(o<<1,l,mid,ql,min(qr,mid),x);
	if(qr>mid) add(o<<1|1,mid+1,r,max(ql,mid+1),qr,x);
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l && r<=qr){
		return tree[o];
	}
	pushdown(o,l,r);
	int mid=(r+l)>>1;
	int ret=0;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,min(qr,mid));
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,max(ql,mid+1),qr);
	return ret;
}

void plus1(int o,int x){
	add(1,1,n,dfn[o],dfn[o],x);
	return ;
}

void plus2(int o,int x){
	add(1,1,n,dfn[o],ht[o],x);
	return ;
}

int Q(int o){
	int ret=0;
	do{
		ret+=query(1,1,n,dfn[top[o]],dfn[o]);
		o=fa[top[o]];
	}while(o!=0);
	return ret;
}

int_ main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<n;i++){
		int tp1,tp2;
		scanf("%lld %lld",&tp1,&tp2);
		ade(tp1,tp2);
		ade(tp2,tp1);
	}
	cnt=0;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,tp1,tp2;
		scanf("%lld",&opt);
		if(opt==1){
			scanf("%lld %lld",&tp1,&tp2);
			plus1(tp1,tp2);
		}
		else if(opt==2){
			scanf("%lld %lld",&tp1,&tp2);
			plus2(tp1,tp2);
		}
		else if(opt==3){
			scanf("%lld",&tp1);
			printf("%lld\n",Q(tp1));
		}
	}
	return 0;
}

