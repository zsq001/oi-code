#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

int X[]={0,0,0,1,-1};
int Y[]={0,1,-1,0,0};
bool vis[2507][2507],book[2507][2507];
bool flag;
char col[2507][2507];
int n,m,sx,sy;

/*
struct node{
	int x,y,w;
}now,next;



inline void bfs(){
	memset(vis,0,sizeof(vis));
	queue<node> qwq;
	now.x=sx,now.y=sy,now.w=0;
	qwq.push(now);
	while(!qwq.empty()){
		now=qwq.front();
		qwq.pop();
		for(int i=1;i<=4;++i){
			next.w=now.w+1;
			next.x=now.x+X[i];
			next.y=now.y+Y[i];
			if(next.x<=0||next.x>n||next.y<=0||next.y>m) continue;
			if(next.x==sx&&next.y==sy&&next.w>=4){
				flag=1;
				return;
			}
			else if(!vis[next.x][next.y]&&col[next.x][next.y]==col[now.x][now.y]){
				qwq.push(next);
				vis[next.x][next.y]=1; 
			}
		}
	}
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=m;++j)
	    book[i][j]|=vis[i][j];
}
*/
void dfs(int dep,int x,int y){
	if(x==sx&&y==sy&&dep>=4){
		flag=1;
		return;
	}
	for(int i=1;i<=4;++i){
		if(x+X[i]<=0||x+X[i]>n||y+Y[i]<=0||y+Y[i]>m)             continue;
		if(col[x][y]!=col[x+X[i]][y+Y[i]]||vis[x+X[i]][y+Y[i]]) continue;
		vis[x+X[i]][y+Y[i]]=1;
		dfs(dep+1,x+X[i],y+Y[i]);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i){
			scanf("%s",col[i]+1);
	}
	for(sx=1;sx<=n;++sx){
		for(sy=1;sy<=m;++sy){
			if(!vis[sx][sy]) dfs(0,sx,sy);
			if(flag){
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
