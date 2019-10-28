#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100010
#define mod 10000000 
#define ll long long
using namespace std;
int T[9][9],ans[9][9],n,mp[9][9],dx[2]={1,-1};
inline bool ctn(){return mp[0][0]+mp[1][0]+mp[2][0]+mp[3][0]+mp[4][0];}
inline void record(){for(int i=1;i<=n;++i) printf("%d %d %d\n",T[i][1],T[i][2],T[i][3]);exit(0);}
inline bool ok(int x){return x>=0&&x<5;}
void dfs(int flr)
{
    if(flr>n){
        if(!ctn()) record();
        return;
    }
    for(int x=0;x<5;++x){
        for(int y=0;y<7;++y){
            if(!mp[x][y]) continue;
            for(int k=0;k<2;++k){
                int X=x+dx[k],Y=y,t[9][9],sign[9][9];
                memset(sign,0,sizeof(sign));
				if((!ok(X))||(mp[x][y]==mp[X][Y])||(k&&mp[X][Y])) continue;
                T[flr][1]=x,T[flr][2]=y,T[flr][3]=dx[k];
                if(ans[1][3]){
                    if(x>ans[flr][1]) continue;
                    else if(x==ans[flr][1]&&y>ans[flr][2]) continue;
                }
                if(!mp[X][Y]) while(Y>=1&&!mp[X][Y-1]) Y--;
                for(int i=0;i<5;++i) for(int j=0;j<7;++j) t[i][j]=mp[i][j]; /*save*/
                int tmp=mp[x][y];
                mp[x][y]=mp[X][Y];
                mp[X][Y]=tmp;
                if(!mp[x][y])
                    for(int j=y+1;j<7;++j){
                        if(!mp[x][j]) continue;
                        int cnt(0);
                        while(j-cnt-1>=0&&!mp[x][j-cnt-1]) cnt++;
                        if(cnt){
                            mp[x][j-cnt]=mp[x][j];
                            mp[x][j]=0;
                        }
                    }
                int fnd=1;
                while(fnd){ /*eliminate*/
                    fnd=0;
                    for(int i=0;i<5;++i)
                        for(int j=0;j<7;++j){
                            if(!mp[i][j]) continue;
                            if(i<3&&mp[i][j]==mp[i+1][j]&&mp[i+1][j]==mp[i+2][j]) sign[i][j]=sign[i+1][j]=sign[i+2][j]=fnd=1;
                            if(j<5&&mp[i][j]==mp[i][j+1]&&mp[i][j+1]==mp[i][j+2]) sign[i][j]=sign[i][j+1]=sign[i][j+2]=fnd=1;
                        }
                    for(int i=0;i<5;++i)
                        for(int j=0;j<7;++j)
                            if(sign[i][j]) mp[i][j]=sign[i][j]=0;
                    for(int i=0;i<5;++i)
                        for(int j=0;j<7;++j){
                            if(mp[i][j]){
                                int cnt(0);
                                while(j-cnt-1>=0&&!mp[i][j-cnt-1]) cnt++;
                                if(cnt){
                                    mp[i][j-cnt]=mp[i][j];
                                    mp[i][j]=0;
                                }
                            }
                        }
                }
                dfs(flr+1);
                for(int i=0;i<5;++i) for(int j=0;j<7;++j) mp[i][j]=t[i][j]; /*restore*/
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<5;++i){
        int x;
        scanf("%d",&x);
        int cnt=0;
        while(x){
            mp[i][cnt++]=x;
            if(cnt==8) break;
            scanf("%d",&x);
        }
    }
    dfs(1);
	puts("-1");
    return 0;
}
