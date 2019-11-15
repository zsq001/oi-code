#include <stdio.h>
int n,m;
int vis[210];
int E[210][210];
double minn=1e9;
void comp(int x,int y){
	double t=(double(x))/(double(y));
	if(t<minn) minn=t;
}
void dfs(int pos,int tot,int dot){
	if(pos==1){
		comp(tot,dot);
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&E[pos][i]>=0){
			vis[i]=1;
			
			dfs(i,tot+E[pos][i],dot+1);
			
			vis[i]=0;
		}
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			E[i][j]=-1;
	for(int i=1;i<=m;i++){
		int a,b,z;
		scanf("%d%d%d",&a,&b,&z);		
		E[b][a]=z;
	}
	vis[n]=1;
	dfs(n,0,1);
	printf("%.3lf",minn);
	return 0;
}
