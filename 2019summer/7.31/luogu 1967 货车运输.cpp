#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define maxn 10010
#define inf 1<<29
using namespace std;
struct Edge{
    int u,v,w,ne;
}E[50010],e[100010];
int cnt,tot,n,m,q,maxdeep,up,fa[maxn],hl[maxn],f[maxn][15],g[maxn][15],deep[maxn],dis[maxn];
void add(int u,int v,int w)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].ne=hl[u];
    hl[u]=cnt;
}
bool cmp(Edge x,Edge y){return x.w>y.w;}
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
void dfs(int x,int pre)
{
    for(int i=hl[x];i;i=e[i].ne){
        int v=e[i].v;
        if(v==pre) continue;
        maxdeep=max(maxdeep,deep[v]=deep[x]+1);
        f[v][0]=x;
        g[v][0]=e[i].w;
        dfs(v,x);
    }
}
void init(){
	for(int j=1;j<=up;++j) 
		for(int i=1;i<=n;++i) 
			if(deep[i]>=(1<<j)){
				f[i][j]=f[f[i][j-1]][j-1];
				g[i][j]=min(g[f[i][j-1]][j-1],g[i][j-1]);
			}
}
inline void swaap(int &x,int &y){x^=y,y^=x,x^=y;}
int getmin(int x,int y)
{
    int tmp=inf;
    if(deep[x]<deep[y]) swaap(x,y);
    int d=deep[x]-deep[y];
    for(int i=up;i>=0;--i) 
		if(d&(1<<i)){
			tmp=min(tmp,g[x][i]);
			x=f[x][i];
		}
	if(x==y) return tmp;
    for(int i=up;i>=0;--i){
        if(f[x][i]!=f[y][i]){
        	tmp=min(tmp,min(g[x][i],g[y][i]));
            x=f[x][i];
            y=f[y][i];
        }
    }
    return min(tmp,min(g[x][0],g[y][0]));
}
int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        int k1=fnd(u),k2=fnd(v);
        if(k1!=k2){
            fa[k1]=k2;
            add(u,v,w);
            add(v,u,w);
            tot++;
        }
        if(tot==n-1) break;
    }
    for(int i=1;i<=n;++i) if(!deep[i]) dfs(i,0);
	up=(int)(log(maxdeep)/log(2));
	init();
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&u,&v);
        if(fnd(u)!=fnd(v)) puts("-1");
        else printf("%d\n",getmin(u,v));
    }
    return 0;
}
