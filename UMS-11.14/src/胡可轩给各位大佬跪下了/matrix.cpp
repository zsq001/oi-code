#include<cstdio>
#define maxn 1000
int m, n, q, map[maxn][maxn];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&m,&n,&q);
	while(q --){
		int flag, y, z;
		scanf("%d%d%d",&flag,&y,&z);
		if(flag == 1)for(int i = 1; i <= n; i ++)map[y][i] = z;
		else for(int i = 1; i <= m; i ++)map[i][y] = z;
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
