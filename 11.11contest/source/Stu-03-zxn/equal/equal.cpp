#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
#define ll long long

int read(){
	int ret=0;char ch=getchar();bool ff=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') ff=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int head[maxn],cnt;

struct node{
	int v,next;
}e[maxn<<1];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int n,rt,fa[maxn][18],dep[maxn],siz[maxn];

void dfs1(int x,int fx){
	fa[x][0]=fx;
	dep[x]=dep[fx]+1;
	siz[x]=1;
	for(int v,i=head[x];i;i=e[i].next){
		v=e[i].v; if(v==fx) continue ;
		dfs1(v,x);
		siz[x]+=siz[v];
	}
}


void init(){
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i<=n;i++){
			if(dep[i]>(1<<j)) fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
}

int find_lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=17;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i]) {
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}


int size(int x,int y,int lca){
	if(fa[x][0]==lca) return siz[x]+siz[y];
	for(int i=17;i>=0;i--){
		if(dep[fa[x][i]]>dep[lca]) return size(fa[x][i],fa[y][i],lca);
	}
}

int find_mid(int x,int len){
	if(len==1) return siz[fa[x][0]]-siz[x];
	for(int i=17;i>=0;i--){
		if(len>(1<<i)) return find_mid(fa[x][i],len-(1<<i));
	}
}

int find(int x,int y){
	if(x==y) return n;
	if(dep[x]<dep[y]) swap(x,y);
	int lca=find_lca(x,y);
	int len=dep[x]-dep[lca]+dep[y]-dep[lca];
	if(len%2) return 0;
	if(dep[x]==dep[y]){
		return n-size(x,y,lca);
	}
	return find_mid(x,len/2);
}

int main(){
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	n=read();
	int a,b;
	for(int i=1;i<n;++i){
		a=read();b=read();
		add(a,b);
	}
	dep[1]=1;
	dfs1(1,0);
	init();
	int m=read();
	while(m--){
		printf("%d\n",find(read(),read()));
	}
	return 0;
}
//4
//1 2
//2 3
//2 4
//2
//1 2
//1 3

//11
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//4 8
//5 9
//6 10
//7 11
