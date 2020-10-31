#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=55;
int n,m;
char mp[N][N];
int vis[N][N],cnt[N*N],col;
int dis[N][N];
int px[N*N],py[N*N],tot;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct node{
	int x,y,d;
	bool operator < (const node _)const{
		return d>_.d;
	}
	bool operator > (const node _)const{
		return d<_.d;
	}
};
priority_queue<node>q;

void dfs(int x,int y){
	px[++tot]=x; py[tot]=y;
	for(int i=0,nx,ny;i<4;i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(nx<1||ny<1||nx>n||ny>m)continue;
		if(vis[nx][ny])continue;
		if(mp[nx][ny]!=mp[x][y])continue;
		vis[nx][ny]=col;
		++cnt[col];
		dfs(nx,ny);
	}
}

bool check(){
	node now;
	int x,y,nx,ny,d;
	for(int i=1;i<=tot;i++){
		now.d=1; now.x=px[i]; now.y=py[i];
		while(!q.empty())q.pop();
		memset(dis,0,sizeof(dis));
		dis[now.x][now.y]=1;
		q.push(now);
		while(!q.empty()){
			now=q.top(); q.pop();
			x=now.x; y=now.y; d=now.d;
			if(d>=4)return 1;
			for(int j=0;j<4;j++){
				nx=x+dx[j]; ny=y+dy[j];
				if(nx<1||ny<1||nx>n||ny>m)continue;
				if(vis[nx][ny]!=col)continue;
				if(dis[nx][ny])continue;
				dis[nx][ny]=d+1;
				now.x=nx; now.y=ny; now.d=d+1;
				q.push(now);
			}
		}
	}
	return 0;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(!vis[i][j]){
			++col; tot=0; dfs(i,j);
			if(check()){puts("Yes");return 0;}
		}
	puts("No");
	return 0;
}
