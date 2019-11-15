#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template <class T> void read (T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
#define maxn 100005
int n,m;
struct Edge{
	int v,next;
}e[maxn<<4];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int f[maxn][20],deep[maxn],st[maxn];
void dfs(int x,int fa){
	f[x][0]=fa;
	deep[x]=deep[fa]+1;
	if(head[x]==0) st[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
		st[x]+=st[v];
	}
	st[x]++;
}
void init(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			if(deep[i]>j) 
				f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
void lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	int d=deep[x]-deep[y],sx=x;	
	if(d%2==1){
		printf("0\n");
		return ;
	}
	for(int i=18;i>=0;i--) 
		if((1<<i)&d) x=f[x][i];
	if(x==y) {
		d=(d>>1)-1;
		for(int i=18;i>=0;i--) 
			if((1<<i)&d) sx=f[sx][i];
		printf("%d\n",st[f[sx][0]]-st[sx]);
		return ;
	}
	for(int i=18;i>=0;i++){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	d=(deep[x]-(d>>1)-1);
	for(int i=18;i>=0;i--) 
		if((1<<i)&d) sx=f[sx][i];
	printf("%d\n",st[f[sx][0]]-st[sx]);
	return ;
}
int u,v,a,b;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++) {
		read(u),read(v);
		add(u,v);add(v,u);
	}
	read(m);
	dfs(1,0);
	init();
	while(m--){
		read(a),read(b);
		if(a==b)printf("%d\n",n-1);
		lca(a,b);
	}
	return 0;
}
