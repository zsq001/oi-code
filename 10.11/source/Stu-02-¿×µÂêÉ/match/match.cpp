#include <stdio.h>
#include <algorithm>
#define maxn 100010
const int bigg = 1 << 29;
using namespace std;
int yel[maxn],blu[maxn];
int vis[maxn];
int n,m,x,y,ans = 0;

void INput() {
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for (int i = 1; i <= n; i ++) 
		scanf("%d",&yel[i]);
	for (int i = 1; i <= m; i ++)
		scanf("%d",&blu[i]);
	yel[n+1] = bigg;
	blu[n+1] = bigg;
}

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	INput();
	if (n <= 1000 && m <= 1000) {
		int flag = 0;
		if (n > m) flag = 1;
		if (flag == 1) {
			int k = 1;
			for (int i = 1; i <= m; i ++) {
				for (int j = k; j <= n; j ++) {
					int left1 = yel[j] - x,right1 = yel[j] + y;
					int left2 = yel[j+1] - x,right2 = yel[j+1] + y;
					if (left1 <= blu[i] && blu[i] <= right1) {
						if (left2 <= blu[i] && blu[i] <= right2) {
							if (abs(blu[i] - yel[j]) <= abs(blu[i] - yel[j+1]) && vis[j] != 1) {
								vis[j] = 1;
								ans ++;
								k = j;
								break;
							}
						} else {
							vis[j] = 1;
							ans ++;
							k = j;
							break;
						}
					}
				}
			}
			printf("%d",ans);
		} else {
			int k = 1;
			for (int i = 1; i <= n; i ++) {
				for (int j = k; j <= m; j ++) {
					int left = yel[i] - x,right = yel[i] + y;
					if (left <= blu[j] && blu[j] <= right) {
						if (left <= blu[j+1] && blu[j+1] <= right) {
							if (abs(blu[i] - yel[j]) <= abs(blu[i+1] - yel[j]) && vis[j] != 1) {
								vis[j] = 1;
								ans ++;
								k = j;
								break;
							}
						} else {
							vis[j] = 1;
							ans ++;
							k = j;
							break;
						}
					}
				}
			}
			printf("%d",ans);
		}
	}
	return 0;
}
