#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 100005
#define inf 1000000007
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
queue <int> q;
struct Edge{
	int v,next,val;
}e[maxn<<4];
int cnt=1,head[maxn];
void add(int u,int v,int val){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].val=val;
	head[u]=cnt;
	e[++cnt].v=u;
	e[cnt].next=head[v];
	e[cnt].val=0;
	head[v]=cnt;
}
int dfn[maxn],s,t;
bool bfs(int s){
	while(q.empty()==0) q.pop();
	dfn[s]=1;
	q.push(s);
	while(q.empty()==0){
		int x=q.front();
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(dfn[v]==0&&e[i].val!=0){
				dfn[v]=dfn[x]+1;
				q.push(v);
			}
			if(v==t) return 1;
		}
	}
	return 0;
}
int dinic(int x,int flow){
	if(x==t) return flow;
	int k;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(dfn[v]!=dfn[x]+1) continue;
		k=dinic(v,min(flow,e[i].val));
		if(k==0) dfn[v]=0;
		flow-=k;e[i].val-=k;e[i^1].val+=k;
	}
	return flow-k;
}
int T,n,k,col[maxn],tmp;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(T);
	while(T--){
		read(n),read(k);
		s=n+1,t=n+2;
		col[1]=1;
		for(int i=1;i<n;i++) {
			read(tmp);
			tmp++;
			if(col[i]) {
				col[tmp]=0;
				add(i,tmp,1);
				add(tmp,t,1);
			}
			else {
				col[tmp]=1;
				add(tmp,i,1);
				add(s,tmp,1);
			}
		}
		int flow=0,ans=0;
		while(bfs(s)){
			if(flow=dinic(s,inf)) ans+=flow;
		}
		printf("%d\n",n-1-ans+k);
	}
	return 0;
}
