#include<bits/stdc++.h>
#define Mod 19260817
using namespace std ;

char mp[103][103][103];
bool vis[103][103][103];
int dx1[3]={0,1,0};
int dz1[3]={0,0,1};
int dx2[3]={0,1,0};
int dy2[3]={0,0,1};
int dz3[3]={0,1,0};
int dy3[3]={0,0,1};
int n,dis,cnt;
void dfs(int x,int y,int z){
	if(x==n&&y==n&&z==n&&(dis==(n-1)*3)){
		cnt++;
		vis[x][y][z]=0;
		return ;
	}
	for(int i=1;i<=2;i++){
		int flag=0;
		if(x+1<=n&&z+1<=n){
			flag=1;
			int X=x+dx1[i],Z=z+dz1[i];
			if(!vis[X][y][z]){
				vis[X][y][z]=1;
				dis++;
				dfs(X,y,z);
				vis[X][y][z]=0;
				dis--;
			}
			if(!vis[x][y][Z]){
				vis[x][y][Z]=1;
				dis++;
				dfs(x,y,Z);
				vis[x][y][Z]=0;
				dis--;
			}
		}
		if(x+1<=n&&y+1<=n&&!flag){
			flag=1;
			int Y=dy2[i]+y,X=dx2[i]+x;
			if(!vis[x][Y][z]){
				vis[x][Y][z]=1;
				dis++;
				dfs(x,Y,z);
				vis[x][Y][z]=0;
				dis--;
			}
			if(!vis[X][y][z]){
				vis[X][y][z]=1;
				dis++;
				dfs(X,y,z);
				vis[x][Y][z]=0;
				dis--;
			}
		}
		if(y+1<=n&&z+1<=n&&!flag){
			flag=1;
			int Y=dy3[i]+y,Z=dz3[i]+z;
			if(!vis[x][Y][z]){
				vis[x][Y][z]=1;
				dis++;
				dfs(x,Y,z);
				vis[x][Y][z]=0;
				dis--;
			}
			if(!vis[x][y][Z]){
				vis[x][y][Z]=1;
				dis++;
				dfs(x,y,Z);
				vis[x][y][Z]=0;
				dis--;
			}
		}
		if(x+1<=n&&!flag){
			flag=1;
			int X=x+1;
			if(!vis[X][y][z]){
				vis[X][y][z]=1;
				dis++;
				dfs(X,y,z);
				vis[X][y][z]=0;
				dis--;
			}
		}
		if(y+1<=n&&!flag){
			flag=1;
			int Y=y+1;
			if(!vis[x][Y][z]){
				vis[x][Y][z]=1;
				dis++;
				dfs(x,Y,z);
				vis[x][Y][z]=0;
				dis--;
			}
		}
		if(z+1<=n&&!flag){
			flag=1;
			int Z=z+1;
			if(!vis[x][y][Z]){
				vis[x][y][Z]=1;
				dis++;
				dfs(x,y,Z);
				vis[x][y][Z]=0;
				dis--;
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
//	freopen("blcup.in","r",stdin);
//	freopen("blcup.out","w",stdout);
	cin>>n;
	dis=0;
	n++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if((i==1)or(i==n))
					mp[i][j][k]=1;
				if((j==1)or(j==n))
					mp[i][j][k]=1;
				if((k==1)or(k==n))
					mp[i][j][k]=1;
			}
	mp[1][1][1]='s';
	mp[n][n][n]='t';
	dfs(1,1,1);
	cout<<cnt<<endl;
	return 0;
}
