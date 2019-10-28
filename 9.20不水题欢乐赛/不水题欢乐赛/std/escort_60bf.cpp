#include<bits/stdc++.h>
using namespace std;

int n,m,t,X;
int f[510][510],s;
int vis[1010],A[1010],ans=1<<29;
void init(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j]=1<<29;
	for(int i = 1; i <= n; i++)f[i][i] = 0;
}
void input(){
	scanf("%d%d%d%d",&m,&t,&s,&X);
	for(int i = 1; i <= t; i++)scanf("%d",&A[i]);
	for(int i = 1; i <= t; i++)scanf("%d",&A[i+t]);
	for(int i = 1; i <= m; i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		f[a][b] = min(c,f[a][b]); f[b][a] = min(d,f[b][a]);
	}
}
void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i!=j&&j!=k&&k!=i)
					f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
}
void dfs(int x,int stud,int home,int rode,int car){
	if(x==(t<<1)){
		ans = min(ans,rode);
		return ;
	}
	for(int i = 1; i <= (t<<1); i++){
		if(!vis[i]&&f[car][A[i]]<(1<<29)){
			if(((i<=t)&&(stud-home+1<=X))||((i>t)&&(vis[i-t]))){
				vis[i] = 1;
				if(i<=t)dfs(x+1,stud+1,home,rode+f[car][A[i]],A[i]);
				else    dfs(x+1,stud,home+1,rode+f[car][A[i]],A[i]);
				vis[i] = 0;
			}
		}
	}
}
int main(){
	scanf("%d",&n); 
	init();
	input();
	floyd();
	dfs(0,0,0,0,s);
	printf("%d",ans);
} 
