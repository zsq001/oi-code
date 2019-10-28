#include<cstdio>
#include<cstring>
int fx,fy,cnt,n,m;
bool f[30][30];
int x[4]={0,0,1,-1},y[4]={-1,1,0,0};
char ch[30][30];
bool dfs(int nx,int ny){
	cnt++;
	if(nx==fx&&ny==fy&&cnt>=4) return 1;
	for(int i=1;i<=4;i++){
		int xx=nx+x[i],yy=ny+y[i];
		if(f[xx][yy]||xx>n||yy>m||xx<1||yy<1||ch[xx][yy]!=ch[nx][ny])
			continue;
		f[xx][yy]=1;
		if(dfs(xx,yy)) return 1;
	}
	return 0;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!f[i][j]) {
				cnt=0;
				if(dfs(fx=i,fy=j)){
					printf("Yes");
					return 0;
				}
			}
		}
	}
	printf("No");
}
