#include <cstdio>
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char s[55][55];
int vis[55][55];
bool flag;
void dfs(int x,int y,int px,int py)
{
 if(vis[x][y])
 {
  flag=true;
  return;
 }
 vis[x][y]=1;
 for(int i=0;i<4;i++)
 {
  int nx=x+dx[i],ny=y+dy[i];
  if(nx==px&&ny==py)continue;
  if(s[x][y]==s[nx][ny])dfs(nx,ny,x,y);
 }
}
int main()
{
 freopen("chess.in","r",stdin);
 freopen("chess.out","w",stdout);
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(!vis[i][j])
    dfs(i,j,0,0);
 puts(flag?"Yes":"No");
 fclose(stdin);
 fclose(stdout);
 return 0;
}
