#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long ll;
int n,ans[9][9],mp[5][7],dx[2]={1,-1};
bool sum(){return mp[0][0]+mp[1][0]+mp[2][0]+mp[3][0]+mp[4][0];}
bool ok(int x){return x>=0&&x<5;}
void dfs(int f)
{
    if(f>n){
        if(!sum()){
        	for(int i=1;i<=n;++i) 
				cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
        	exit(0);
		}
        return;
    }
    for(int x=0;x<5;++x){
        for(int y=0;y<7;++y){
            if(!mp[x][y]) continue;
            for(int k=0;k<2;++k){
                int X=x+dx[k],Y=y,t[5][7],sign[5][7];
                memset(sign,0,sizeof(sign));
				if((!ok(X))||(mp[x][y]==mp[X][Y])||(k&&mp[X][Y])) continue;
                ans[f][1]=x,ans[f][2]=y,ans[f][3]=dx[k];
                if(!mp[X][Y]) while(Y>=1&&!mp[X][Y-1]) Y--;
                memcpy(t,mp,sizeof(mp));
                swap(mp[x][y],mp[X][Y]);
                if(!mp[x][y])
                    for(int j=y+1;j<7;++j){
                        mp[x][j-1]=mp[x][j];
                        mp[x][j]=0;
                    }
                int fnd=1;
                while(fnd){
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
                        for(int j=1;j<7;++j){
                            if(!mp[i][j-1]){
                                int cnt(0);
                                while(j-cnt-1>=0&&!mp[i][j-cnt-1]) cnt++;
                                mp[i][j-cnt]=mp[i][j];
                            	mp[i][j]=0;
                            }
                        }
                }
                dfs(f+1);
                memcpy(mp,t,sizeof(t));
            }
        }
    }
}
int main()
{
   	cin>>n;
    for(int i=0;i<5;++i){
        int x,cnt=0;
        cin>>x;
        while(x){
            mp[i][cnt++]=x;
            if(cnt==8) break;
            cin>>x;
        }
    }
    dfs(1);
	puts("-1");
    return 0;
}
