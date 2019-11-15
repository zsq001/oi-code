#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
const int N=1e5+100;
struct Edge{
	int v,next;
}e[N<<1];

int tot,n,m,c,head[N],dep[N],fa[N][25];
int siz[N],cha,len,ans,f,u,v,q;

inline void add(int u,int v){
	e[++tot].next=head[u];
	e[tot].v=v;
	head[u]=tot;
}

inline void dfs(int u,int f){
    fa[u][0]=f;
    for(int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].next)
        if(e[i].v!=f){
            dep[e[i].v]=dep[u]+1;
            dfs(e[i].v,u);
            siz[u]+=siz[e[i].v];
        } 
}

inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
        if((1<<i)&(dep[x]-dep[y])) x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int main()
{
    freopen("equal.in","r",stdin);
    freopen("equal.out","w",stdout);
    read(n);
    for(int i=1;i<n;i++){
    	read(u),read(v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++) siz[i]=1;
    dep[1]=0;
    dfs(1,0);
    read(m);
    while(m--){
    	read(u),read(v);
        if(u==v){printf("%d\n",n);continue;}
        c=lca(u,v);
        len=dep[u]+dep[v]-2*dep[c];
        if(len&1){printf("0\n");continue;}
        if(dep[u]<dep[v]) swap(u,v);
        int d=len/2;
        if(dep[u]==dep[v]){
            q=u;f=v;
            for(int i=20;i>=0;i--)
                if((d-1)&(1<<i)) q=fa[q][i];
            for(int i=20;i>=0;i--)
                if((d-1)&(1<<i)) f=fa[f][i];
                ans=n-siz[q]-siz[f];
        }
        else{
            q=f=u;
            for(int i=20;i>=0;i--)
                if(d&(1<<i)) q=fa[q][i];
            for(int i=20;i>=0;i--)
                if((d-1)&(1<<i)) f=fa[f][i];
            ans=siz[q]-siz[f];
        }
		printf("%d\n",ans);
    }
    return 0;
}
