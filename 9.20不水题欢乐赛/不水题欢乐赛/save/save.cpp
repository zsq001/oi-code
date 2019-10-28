#include<bits/stdc++.h>
using namespace std;
int n,K;
int dis[30][30];
int f[1<<20][20];
int lock[30][6][6],mp[6][6];
int ans;
void input(){
	scanf("%d%d",&n,&K);
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d",&t);
		dis[0][i]=dis[i][0]=t; 
	}
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d",&t);
		dis[n+1][i]=dis[i][n+1]=t; 
	}
	for(int i = 1; i <= n; i++)	
		for(int j = 1; j <= n; j++){
			int t;
			scanf("%d",&t);
			dis[j][i]=dis[i][j]=t; 
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 5; j++)
			for(int k = 1; k <= 5; k++)
				scanf("%d",&lock[i][j][k]);
}
void work_run(){
	int N=n+2;
	memset(f,0x3f,sizeof f);
	f[1][0] = 0;	
	for(int i = 0; i < 1<<N; i++)	
		for(int j = 0; j < N; j++)
			if((i>>j) & 1)
				for(int k = 0; k < N; k++)
					if(((i ^ 1<<j)>>k)& 1)
						f[i][j] = min(f[i][j],f[i ^ (1<<j)][k]+dis[k][j]);
	ans+=f[(1<<N)-1][N-1];
} 
bool check(){
	for(int i = 1; i <= 5; i++)
		if(mp[5][i])return 0;
	return 1;
}
void work_lock(){
	for(int i = 1; i <= n; i++){
		int ccnt = 1<<20;
		for(int j = 0; j < 1<<5; j++){
			int cnt = 0;
			for(int x = 1; x <= 5; x++)
				for(int y = 1; y <= 5; y++)
					mp[x][y] = lock[i][x][y];
			for(int l = 1; l <= 5; l++)
				if((j>>l-1)&1){
					cnt++;
					mp[1][l]^=1;mp[2][l]^=1;
					if(l-1>0)mp[1][l-1]^=1;if(l+1<6)mp[1][l+1]^=1;
				}
			for(int l = 2; l <= 5; l++){
				for(int k = 1; k <= 5; k++){
					if(mp[l-1][k]){
						cnt++;
						mp[l][k]^=1;mp[l-1][k]^=1;
						if(k-1>0)mp[l][k-1]^=1;
						if(k+1<6)mp[l][k+1]^=1;
						if(l+1<6)mp[l+1][k]^=1;
					}
				}
			}
			if(check())ccnt = min(ccnt,cnt);
		}
		ans += ccnt*K;
	}
}
int main(){
	input();
	work_lock();
	if(ans>=(1<<20)){puts("NO");return 0;}
	work_run();
	printf("YES\n%d",ans);
}
