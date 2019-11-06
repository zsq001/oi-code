#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 100005
#define ll long long
int read(){
	int ret=0;char c;c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){ ret=(ret<<3)+(ret<<1)+(c&15);c=getchar();}
	return ret;
}
struct node{
	int v,next;
}e[maxn<<1];
int lazy[maxn],cnt,dep[maxn],fa[maxn],w[maxn],head[maxn];

void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].v=v;
	head[u]=cnt;
}

ll query(int x){
	int ret=0;
	int xx=x;
	while(xx){
		ret+=1ll*w[xx];
		if(lazy[xx])ret+=1ll*(dep[x]-dep[xx]+1)*lazy[xx];
		xx=fa[xx];
	}
	return ret;
}

void build(int x,int fx){
	fa[x]=fx;
	dep[x]=dep[fx]+1;
	for(int i=head[x],v;i;i=e[i].next){
		v=e[i].v;
		if(v==fx)continue;
		build(v,x);
	}
}

int main(){
	int n,m,x,y;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		w[i]=read();
	}
	dep[1]=1;
	for(int i=1;i<n;i++){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	build(1,0);
	int op;
	while(m--){
		op=read();x=read();
		if(op==1){
			y=read();
			w[x]+=y;
		}
		if(op==2){
			y=read();
			lazy[x]+=y;
		}
		if(op==3){
			printf("%lld\n",query(x));
		}
	}
}
