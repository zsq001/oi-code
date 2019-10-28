#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson o<<1,l,Mid
#define rson o<<1|1,Mid+1,r
#define MID Mid=(l+r)>>1
#define maxn 1000010 
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int n,m,Root,p;
struct Edge{
	int u,v,next;
}E[maxn<<1];
int head[maxn],ecnt;
void addedge(int u,int v){
	E[++ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
void Addedge(int aa,int bb){
	addedge(aa,bb);
	addedge(bb,aa);
}
int dep[maxn],siz[maxn],fa[maxn],hv[maxn],top[maxn];
void dfs1(int x,int fx){
	dep[x]=dep[fx]+1;
	siz[x]=1;
	fa[x]=fx;
	int maxx=0;
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(v==fx) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxx){
			maxx=siz[v];
			hv[x]=v;
		}
	}
}
int dfn[maxn],cnt=0,wt[maxn],w[maxn];
int tr[maxn];
void dfs2(int x,int topp){
	top[x]=topp;
	dfn[x]=++cnt;
	wt[cnt]=w[x];
	if(hv[x]==0) return;
	dfs2(hv[x],topp);
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(v==fa[x]||v==hv[x]) continue;
		dfs2(v,v);
	}
}
int lazy[maxn];
void pushup(int o,int l,int r){
	int MID;
	tr[o]=tr[o<<1]+tr[o<<1|1]+lazy[o<<1]*(Mid-l+1)+lazy[o<<1|1]*(r-Mid);
	tr[o]%=p;
}
void pushdown(int o,int l,int r){
	if(lazy[o]){
		if(l==r){
			tr[o]+=lazy[o];
			tr[o]%=p;
			lazy[o]=0;
			return ;
		}
		lazy[o<<1]+=lazy[o];
		lazy[o<<1|1]+=lazy[o];
		lazy[o<<1]%=p;
		lazy[o<<1|1]%=p;
		lazy[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r){
		tr[o]=wt[l]%p;
		return ;
	}
	int MID;
	build(lson);
	build(rson);
	pushup(o,l,r);
}
int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return (tr[o]+lazy[o]*(r-l+1))%p;
	}
	pushdown(o,l,r);
	int MID,ret=0;
	if(ql<=Mid) ret+=query(lson,ql,qr);
	if(qr>Mid) ret+=query(rson,ql,qr);
	pushup(o,l,r);
	return ret%p;
}
void update(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		lazy[o]+=val;
		lazy[o]%=p;
		return ;
	}
	pushdown(o,l,r);
	int MID;
	if(ql<=Mid) update(lson,ql,qr,val);
	if(qr>Mid) update(rson,ql,qr,val);
	pushup(o,l,r);
}

void Update2(int x,int val){
	update(1,1,n,dfn[x],dfn[x]+siz[x]-1,val);
}
int Query2(int x){
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}
void Update1(int x,int y,int val){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],val);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(1,1,n,dfn[x],dfn[y],val);
}
int Query1(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ret+=query(1,1,n,dfn[top[x]],dfn[x]);
		ret%=p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ret+=query(1,1,n,dfn[x],dfn[y]);
	return ret%p;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&Root,&p);
	for(int i=1;i<=n;++i) scanf("%d",&w[i]);
	for(int i=1;i<n;++i){
		int aa,bb;
		scanf("%d%d",&aa,&bb);
		Addedge(aa,bb);
	}
	
	dfs1(Root,0);//puts("wqwq");
	dfs2(Root,Root);
	build(1,1,n);
	while(m--){
	//	puts("qwqwq");
		int op=read();
		int x=read();
		if(op==1){
			int y=read(),z=read();
			Update1(x,y,z%p);
		}
		if(op==2){
			int y=read();
			printf("%d\n",Query1(x,y));
		}
		if(op==3){
			int z=read();
			Update2(x,z%p);
		}
		if(op==4){
			printf("%d\n",Query2(x));
		}
	}
}
