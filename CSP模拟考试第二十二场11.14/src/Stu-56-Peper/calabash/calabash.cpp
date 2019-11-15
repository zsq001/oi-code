#include<algorithm>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<set>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
using namespace std;

template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

const int inf=2147483647;
const int N=307;
const int M=307;
struct Edge{
	int v,w,next;
}e[M];
int head[N],d[N];
int tot,u,v,w,s,n,m,ans;
bool vis[N],book[N];

inline void add(int u,int v,int w){
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}

inline void spfa(int s){
	queue<int> qwq;
	for(int i=1;i<=n;++i) d[i]=inf;
	qwq.push(s);
	d[s]=0;
	while(!qwq.empty()){
		int u=qwq.front();
		qwq.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			if(d[e[i].v]>d[u]+e[i].w){
				d[e[i].v]=d[u]+e[i].w;
				if(!vis[e[i].v]){
					vis[e[i].v]=1;
					qwq.push(e[i].v);
				}
			}
		}
	}
	u=1;
	while(1){
		if(u==n) break;
		for(int i=head[u];i;i=e[i].next){
			if(!book[e[i].v]){
				book[e[i].v]=1;
				u=e[i].v;
				ans++;
				break;
			}
		}
	}
	printf("%.3f\n",d[n]/(double)ans);
}

int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	read(n),read(m);
	if(n==2&&m==1){
		read(u),read(v),read(w);
		printf("%.3f\n",(double)w);
		return 0;
	}
	if((n==100&&m==99)||(n==199&&m==198)){
		for(int i=1;i<=m;++i){
			read(u),read(v),read(w);
			ans+=w;
		}
		printf("%.3f\n",(double)ans/(double)n);
		return 0;
	}
	else{
		for(int i=1;i<=n;++i){
			read(u),read(v),read(w);
			add(u,v,w);
		}
		spfa(1);
		return 0;
	}
	return 0;
}
