#include<stdio.h>
#include<cmath>

	int n,m,a[50][10],ans=0;

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int sum=0;
	for(int j=1;j<=m;j++)sum+=a[1][j];
	if(n==2){
	    for(int j=1;j<=m;j++){
	    	if(a[1][j]==0&&a[2][j]!=0)ans+=a[2][j]*sum;
	    	if(a[1][j]!=0&&a[2][j]!=0)ans+=a[2][j]*(sum-a[1][j]);
	    }
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
