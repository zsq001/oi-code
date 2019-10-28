#include<cstdio>
#include<algorithm>
using namespace std;
int a[101][101][101];
int main(){
	int n;
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%d",&n);
	a[1][1][1]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
			for(int k=1;k<=n+1;k++){
				if( (i==(n+1)||j==(n+1)||k==(n+1)||i==1||j==1||k==1) ){
					if(i==1&&j==1&&k==1)continue;
					a[i][j][k]=(a[i-1][j][k]+a[i][j-1][k]+a[i][j][k-1])%19260817;
				}
			}
	printf("%d",a[n+1][n+1][n+1]);
	return 0;
}
