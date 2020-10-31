#include<cstdio>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1<<29
#define maxn 50010
using namespace std;
struct Edge{
	int v,w,ne;
}e[maxn];
int n,m,q,ex,ey,sx,sy,tx,ty,cnt,ans,dis[40][40],mp[40][40],ds[5010],hl[5010],qx[5010],qy[5010],vis[5010],dx[]={-1,1,0,0},dy[]={0,0,-1,1};
queue<int>Q;
void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].ne=hl[u];
	hl[u]=cnt;
}
inline int cal(int x,int y){return x*120+y*4;}
void bfs(int x,int y,int xx,int yy,int f)
{
	int head=0,tail=1;
	memset(dis,0,sizeof(dis));
	dis[x][y]=dis[xx][yy]=1;
	qx[1]=x,qy[1]=y;
	while(head<tail){
		head++;
		int nx=qx[head],ny=qy[head];
		for(int i=0;i<4;++i){
			int X=nx+dx[i],Y=ny+dy[i];
			if(mp[X][Y]&&(!dis[X][Y])){
				dis[X][Y]=dis[nx][ny]+1;
				qx[++tail]=X;
				qy[tail]=Y;
			}
		}
	}
	if(f==4) return;
	dis[x][y]=0;
	for(int i=0;i<4;++i){
		int X=xx+dx[i],Y=yy+dy[i];
		if(dis[X][Y]) add(cal(xx,yy)+f,cal(xx,yy)+i,dis[X][Y]-1);
	}
	dis[x][y]=1;
	add(cal(xx,yy)+f,cal(x,y)+f^1,1);
}
void spfa(int x,int y)
{
	for(int i=0;i<=5010;++i) ds[i]=inf,vis[i]=0;	
	for(int i=0;i<4;++i){
		int X=x+dx[i],Y=y+dy[i],state=cal(x,y)+i;
		if(dis[X][Y]){
			ds[state]=dis[X][Y]-1;
			Q.push(state);
			vis[state]=1;
		}
	}
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		vis[u]=0;
		for(int i=hl[u];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if(ds[v]>ds[u]+w){
				ds[v]=ds[u]+w;
				if(!vis[v]){
					vis[v]=1;
					Q.push(v);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(!mp[i][j]) continue;
			for(int k=0;k<4;++k){
				int X=i+dx[k],Y=j+dy[k];
				if(mp[X][Y]) bfs(X,Y,i,j,k);
			}
		}
	while(q--){
		ans=inf;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if(sx==tx&&sy==ty){
			puts("0");
			continue;
		}
		bfs(ex,ey,sx,sy,4);
		spfa(sx,sy);
		for(int i=0;i<4;++i) ans=min(ans,ds[cal(tx,ty)+i]);
		printf("%d\n",ans<inf?ans:-1);
	}
    return 0;
}
