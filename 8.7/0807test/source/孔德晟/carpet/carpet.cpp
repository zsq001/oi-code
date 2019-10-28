#include <cstdio>
#include <algorithm>
using namespace std;

int dis[55][55];
int main() {
	int n,m;
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
//	if (n <= 50 && m <= 100){
		int x1,y1,x2,y2;
		while(m--){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					dis[i][j]++;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				printf("%d",dis[i][j]);
			printf("\n");	
		}
//	} else {
//		for (int i = 1; i <= m ;i++) 
//	}
	return 0;
}
