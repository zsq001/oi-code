#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define inf 1<<29
using namespace std;
int ans=1,n,m,cnt,mp[510][510],vis[510][510],jh[510][510],ex[510],dx[]={0,1,0,-1},dy[]={1,0,-1,0},f[510];
struct seg{
    int l,r;
}s[510];
bool ok(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
bool cmp(seg x,seg y){if(x.l==y.l) return x.r>y.r;return x.l<y.l;}
void dfs(int id,int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;++i){
        int X=dx[i]+x,Y=dy[i]+y;
        if(ok(X,Y)&&!vis[X][Y]&&mp[X][Y]>mp[x][y]) dfs(id,X,Y);
    }
    if(x==1){
        jh[y][id]=1;
        if(!ex[id]) ex[id]=1,cnt++;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&mp[i][j]);
    for(int i=1;i<=m;++i) memset(vis,0,sizeof(vis)),dfs(i,n,i);
    if(cnt<m){
        printf("0\n%d",m-cnt);
        return 0;
    }
    for(int i=1;i<=m;++i){
        s[i].l=510;
        for(int j=1;j<=m;++j){
            if(jh[i][j]){
                s[i].l=min(s[i].l,j);
                s[i].r=max(s[i].r,j);
            }
            else if(s[i].r) break;
        }
    }
    for(int i=1;i<=m;++i){
        f[i]=inf;
        for(int j=1;j<=m;++j) if(s[j].l<=i&&i<=s[j].r) f[i]=min(f[i],f[s[j].l-1]+1);
    }
    printf("1\n%d",f[m]);
    return 0;
}
