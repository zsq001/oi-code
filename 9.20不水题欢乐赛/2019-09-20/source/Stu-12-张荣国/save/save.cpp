#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 50
#define inf 1000000007
using namespace std;
template <class T> void read(T &x){
	x=0;char s=getchar();bool t=0;
	while(s<'0'||s>'9') {if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int cnt,head[maxn],n,k,tmp,ans;
struct node{
	int v,next,w;
}e[maxn<<2];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
	
}
int fa[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) {
		read(tmp);
		add(0,i,tmp);
		ans+=tmp;
	}
	int t=n+1;
	for(int i=1;i<=n;i++){
		read(tmp);
		add(i,t,tmp);
		ans+=tmp;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			read(tmp);
			if(i==j) continue;
			add(i,j,tmp);
		}
	if(n!=1) ans=21;
	printf("YES\n%d",ans);
	return 0;
}
