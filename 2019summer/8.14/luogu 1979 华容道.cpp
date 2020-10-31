#include<bits/stdc++.h>
#define inf 1<<29
#define maxn 50010
using namespace std;
struct Cell{
	int x,y;
	Cell(int a,int b){x=a,y=b;}
};
struct Edge{
	int v,w,next;
}e[maxn];
int n,m,q,ex,ey,sx,sy,tx,ty,cnt,ans,dis[40][40],mp[40][40],DIS[5010],head[5010],vis[5010],dx[]={-1,1,0,0},dy[]={0,0,-1,1};
void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
inline int cal(int x,int y){return x*120+y*4;}
void bfs(int x,int y,int xx,int yy,int f)
{
	queue<Cell>Q;
	memset(dis,0,sizeof(dis));
	dis[x][y]=dis[xx][yy]=1;
	Q.push(Cell(x,y));
	while(!Q.empty()){
		Cell now=Q.front();
		Q.pop();
		int nx=now.x,ny=now.y;
		for(int i=0;i<4;++i){
			int X=nx+dx[i],Y=ny+dy[i];
			if(mp[X][Y]&&(!dis[X][Y])){
				dis[X][Y]=dis[nx][ny]+1;
				Q.push(Cell(X,Y));
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
void spfa(int x,int y){
	queue<int>Q;
	for(int i=0;i<=5010;++i) DIS[i]=inf,vis[i]=0;	
	for(int i=0;i<4;++i){
		int X=x+dx[i],Y=y+dy[i],state=cal(x,y)+i;
		if(dis[X][Y]){
			DIS[state]=dis[X][Y]-1;
			Q.push(state);
			vis[state]=1;
		}
	}
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(DIS[v]>DIS[u]+w){
				DIS[v]=DIS[u]+w;
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
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>mp[i][j];
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
		cin>>ex>>ey>>sx>>sy>>tx>>ty;
		if(sx==tx&&sy==ty){
			puts("0");
			continue;
		}
		bfs(ex,ey,sx,sy,4);
		spfa(sx,sy);
		for(int i=0;i<4;++i) ans=min(ans,DIS[cal(tx,ty)+i]);
		cout<<(ans<inf?ans:-1)<<endl;
	}
    return 0;
}
