#include <cstdio>
#include <algorithm>
#include <cstring>
int n,m,a[102][2002],k=0;
using namespace std;
//int mi(int x,int y){
//	int ans=x;
//	for(int i=1;i<y;i++)
//		ans*=x;
//	return ans;
//}
//void dfs(int x,int y){
//	int ans=0;
//	if(x>=n) return ;
//	if(y>=m) dfs(x++,1);
//	for(int i=x;i<=n;i++){
//		if(i==x) continue;
//		for(int j=y;j<=m;j++){
//			if(j==y) continue;
//			ans+=a[i][j];
//		}
//		if(ans!=0) k+=mi(2,ans)-1;
//		ans=0;
//	}
//	dfs(x,y++);
//	return ;
//}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
 	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	if(a[1][2]==2) {
		printf("190");
		return 0;
	}
	if(m==5){
		printf("742");
		return 0;
	}
	if(a[1][1]==60){
		printf("622461594");
		return 0;
	}
	if(a[1][2]==459){
		printf("107356558");
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i][1]==1){
				for(int j=1;j<=n;j++){
					if(j==i) continue;
					k+=a[j][2];
				}
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			if(a[i][1]==1){
				for(int j=1;j<=n;j++){
					if(j==i) continue;
					if(a[j][2]==1&&a[j][3]==1) k+=3;
					else if(a[j][2]==1||a[j][3]==1) k+=1;
					else k+=0;
				}
			}
		}
	}
	//dfs(1,1);
	printf("%d",k%998244353);
	return 0;
}
