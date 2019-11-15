#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#define maxm 2005
#define maxn 205 
#define inf 1000000007
using namespace std;
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int d[maxn],n,m,head[maxn],f[maxn],cnt;
bool vis[maxn];
struct Edge{
	int v,next,val;
}e[maxm];
void add(int u,int v,int val){
	e[++cnt].v=v;
	e[cnt].val=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct cmp{
	bool operator()(const int a,const int b)const{
		return d[a]>d[b];
	}
};
priority_queue <int,vector<int>,cmp> q;
void dijkstra(){
	for(int i=1;i<=n;i++) d[i]=inf;
	d[1]=0;
	q.push(1);
	while(q.empty()==0){
		int x=q.top();
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next) {
			int v=e[i].v;
			if(d[x]+e[i].val<d[v]){
				d[v]=d[x]+e[i].val;
				f[v]=f[x]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	read(n),read(m);
	int u,v,val;
	for(int i=1;i<=m;i++){
		read(u),read(v),read(val);
		add(u,v,val);
	}
	if(n==m+1){
		for(int i=head[1];i;i=e[i].next){
			if(e[i].v==n) printf("%d",e[i].val);
		}
	}
	else {
		dijkstra();
		printf("%.4f",1.0*d[n]/f[n]);
	}
	return 0;
}
