#include<stdio.h>
int a[210][210];
int b[210];
int n;
double min=9999999999;
void dfs(int x,int e,int s){
	if(x==n){
		double y=e/s;
		if(y<min)min=y;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]>0&&b[i]==0){
			b[i]=1;
			e=e+a[x][i];
			s=s+1;
			dfs(i,e,s);
			e=e-a[x][i];
			s=s-1;
		}
	}
	
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int m,i,j,u,v,w;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
	}
	b[1]=1;
    dfs(1,0,1);
	printf("%.3lf",min);
}
