#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<ctime>
#define mod 19260817
using namespace std;
int TT,T,t,cnt,op,tot,tmp,list[210],mp[7][7],record[110][2],operate[110][2],ans,board[7][7],DX[]={1,0,-1,0},DY[]={0,1,0,-1};
inline bool ok(int x,int y){return x>=1&&x<=6&&y>=1&&y<=6;}
void explode(int,int);
void eliminate(int x0,int y0,int dx,int dy){
	int i=x0,j=y0;
	while(ok(i+dx,j+dy)){
		i+=dx,j+=dy;
		if(mp[i][j]){
			mp[i][j]++;
			list[++list[0]]=(i-1)*6+j-1;
			if(mp[i][j]==5) explode(i,j);
			break;
		}
	}
}
void explode(int x0,int y0){
	mp[x0][y0]=0;
	for(int k=0;k<4;++k) eliminate(x0,y0,DX[k],DY[k]);
}
bool empty(){
	for(int i=1;i<=6;++i) 
		for(int j=1;j<=6;++j)
			if(mp[i][j]) return false;
	return true;
}
void dfs(int step){
	if(empty()){
		for(int i=1;i<=6;++i)
			for(int j=1;j<=6;++j)
				mp[i][j]=board[i][j];
		int x,y;
		memset(list,0,sizeof(list));
		for(int i=step;i>=1;--i){
			x=record[i][0],y=record[i][1];
			mp[x][y]++;
			if(mp[x][y]==5) explode(x,y);
		}
		if(empty()){
			ans=step;
			for(int i=1;i<=step;++i) operate[i][0]=record[i][0],operate[i][1]=record[i][1];
		}
		return;
	}
	int nx,ny,val=1<<29,vis[40];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=list[0];++i){
		nx=list[i]/6+1,ny=list[i]%6+1;
		if(!mp[nx][ny]) continue;
		val=5-mp[nx][ny];
		if(step+val>T) continue;
		if(vis[(nx-1)*6+ny-1]) continue;
		vis[(nx-1)*6+ny-1]=1;
		int tmp[7][7],tl[210];
		memcpy(tmp,mp,sizeof(mp));
		tl[0]=list[0];
		for(int k=1;k<=list[0];++k) tl[k]=list[k];
		for(int k=step+1;k<=step+val;++k) record[k][0]=nx,record[k][1]=ny;
		explode(nx,ny);
		dfs(step+val);
		if(ans) return;
		memcpy(mp,tmp,sizeof(tmp));
		list[0]=tl[0];
		for(int k=1;k<=tl[0];++k) list[k]=tl[k];
	}
}
int main()
{
//	freopen("splash.in","r",stdin);
//	freopen("splash.out","w",stdout);
	cin>>TT>>op;
	while(TT--){
		tot=ans=T=0;
		for(int i=1;i<=6;++i)
			for(int j=1;j<=6;++j){
				cin>>tmp;
				board[i][j]=tmp;
				if(tmp) tot++;
			}
		while(!ans){
			T++;
			for(int i=1;i<=6;++i){ 
				for(int j=1;j<=6;++j)
					if(board[i][j]){
						if(5-board[i][j]>T) continue;
						memcpy(mp,board,sizeof(board));
						for(int k=1;k<=5-board[i][j];++k) record[k][0]=i,record[k][1]=j;
						explode(i,j);
						dfs(5-board[i][j]);
						memset(list,0,sizeof(list));
						if(ans) break;
					}
				if(ans) break;
			}
		}
		cout<<20-ans+(op-1)*(tot/3)<<endl;
	}
	return 0;
}
