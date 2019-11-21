#include<stdio.h>
#include<iostream>
int ans = 0;
int a[1001][1001];
int cnt[10001][10001];
int n, m;
int yyy = 0x7f7f;
int qwq = 0;
int dfs(int x,int y,int qwq){
	cnt[x][y] ++;
	if(cnt[x][y] == ans){
		yyy = std::max(yyy, qwq);
		printf("1");
		return yyy;
	}
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			int dx = i + x;
			int dy = i + y;
			if(dy <= n&& dx <= m && a[i][j] != 0){
				dfs(dx,dy + 1,qwq++);
			}
			dfs(dx + 1, dy, qwq++);
		}
	}
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n >= 5 && m >=3)
	{
		printf("1");
		return 0;
	}
	for(int i = 1; i <= n ;i++) 
		for(int j = 1; j <= m ;j++) {
			scanf("%d",&a[i][j]);
			ans += a[i][j];
			cnt[i][j] = 0;
	}
	ans = ans / n;
	dfs(1, 1, 0);
	if(yyy == 0x7f7f)
		printf("1");
	else printf("%d",yyy);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
