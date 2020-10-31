#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define inf 1<<29
#define maxn 1510
using namespace std;
typedef long long ll;
int mp[maxn][maxn],vis[maxn][maxn][2],n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char s[maxn];
bool dfs(int x,int y)
{
    int X=(x%n+n)%n,Y=(y%m+m)%m;
    if(mp[X][Y]) return false;
    if(vis[X][Y][0]!=8848) return (vis[X][Y][0]!=x)||(vis[X][Y][1]!=y);
    vis[X][Y][0]=x,vis[X][Y][1]=y;
    for(int i=0;i<4;++i) if(dfs(x+dx[i],y+dy[i])) return true;
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int si,sj;
        for(int i=0;i<n;++i){
            scanf("%s",s);
            for(int j=0;j<m;++j){
                vis[i][j][0]=8848;
                if(s[j]=='#') mp[i][j]=-1;
                else{
                    mp[i][j]=0;
                    if(s[j]=='S') si=i,sj=j;
                }
            }
        }
        if(dfs(si,sj)) puts("Yes");
        else puts("No");
    }
    return 0;
}
