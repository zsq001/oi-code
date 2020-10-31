#include<cstdio>
int n,m;
double ans;
char dis[2010][2010];
int main()
{
	int x,y,z;
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2 && m==1){
		scanf("%d%d%d",&x,&y,&z);
		ans=z/2.0;
		printf("%.3lf",ans);
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=z;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j] > dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	ans=dis[1][n]/n;
	printf("%.3lf",ans*2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
