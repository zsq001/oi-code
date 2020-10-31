#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef double db;
const int N=205;
const int M=2005;

int n,m;
struct edge{int to,next,val;}e[N];
int head[N],tot;
struct stat{
	int x,d,p;
	bool operator < (const stat _)const{
		return d>_.d;
	}
	bool operator > (const stat _)const{
		return d<_.d;
	}
};
int dis[N][N];
bool vis[N][N];
priority_queue<stat>q;
db ans=1e9;

void add(int x,int y,int z){
	e[++tot]=(edge){y,head[x],z}; head[x]=tot;
}

void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	int x,y,d,p;
	stat now=(stat){1,0,0};
	dis[1][0]=0;
	q.push(now);
	while(!q.empty()){
		now=q.top(); q.pop();
		x=now.x; d=now.d; p=now.p;
		if(vis[x][p])continue;
		vis[x][p]=1;
		for(int i=head[x];i;i=e[i].next){
			if(dis[y=e[i].to][p+1]>d+e[i].val){
				dis[y][p+1]=d+e[i].val;
				q.push((stat){y,dis[y][p+1],p+1});
			}
		}
	}
}

int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	read(n); read(m);
	int x,y,z;
	for(int i=1;i<=m;i++){
		read(x); read(y); read(z);
		add(x,y,z);
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[n][i]==dis[0][0])continue;
		ans=min(ans,1.0*dis[n][i]/(1.0*(i+1)));
	}
	printf("%.3lf\n",ans);
	return 0;
}
