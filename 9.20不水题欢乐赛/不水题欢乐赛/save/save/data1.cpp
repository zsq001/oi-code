#include<bits/stdc++.h> 
using namespace std;
int n,K;
int dis[30][30],lock[30][30][30],mp[30][30],mpp[30][30];
bool check(){
	for(int i = 1; i <= 5; i++)
		if(mp[5][i])return 0;
	return 1;
}
bool work_lock(){
	int ans = 0;
		int ccnt = 1<<20;
		for(int j = 0; j < 1<<5; j++){
			int cnt = 0;
			for(int x = 1; x <= 5; x++)
				for(int y = 1; y <= 5; y++)
					mp[x][y] = mpp[x][y];
			for(int l = 1; l <= 5; l++)
				if((j>>l-1)&1){
					cnt++;
					mp[1][l]^=1;mp[2][l]^=1;
					if(l-1>0)mp[1][l-1]^=1;
					if(l+1<6)mp[1][l+1]^=1;
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
		//ans = 1; 
	return ans < 1<<20;
}
int main(){
	freopen("save10.in","w",stdout);
	srand(time(0));
	n = 15;
	K = rand()%5+1;
	printf("%d %d\n",n,K);
	for(int i = 1; i <= n; i++)printf("%d ",rand()%50+1);
	puts("");
	for(int i = 1; i <= n; i++)printf("%d ",rand()%50+1);
	puts("");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = rand()%50+1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dis[i][j] = (i==j)?0:dis[j][i];
			
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)printf("%d ",dis[i][j]);
		puts("");
	}
	int top = 0;
	while(top<=n){
			for(int j = 1; j <= 5; j++){
				for(int k = 1; k <= 5; k++)
					mpp[j][k]=rand()%2;
			}
			if(work_lock()){
				top++;
				
				for(int j = 1; j <= 5; j++){
					for(int k = 1; k <= 5; k++)
						lock[top][j][k] = mpp[j][k];
					}
			}
	}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 5; j++){
				for(int k = 1; k <= 5; k++)
					printf("%d ",lock[i][j][k]);
				puts("");
			}
	}
}

