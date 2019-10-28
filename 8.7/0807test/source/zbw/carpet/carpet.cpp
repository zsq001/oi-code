#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,map[1010][1010];
int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int	lx,ly,rx,ry;
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		for(int k=lx;k<=rx;k++){
			for(int j=ly;j<=ry;j++){
				map[k][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",map[i][j]);
		}
		puts("");
	}
	
	return 0;
}
