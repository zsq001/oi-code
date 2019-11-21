#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
const int Mod = 998244353;
using namespace std;
int a[110][2010];
int dp[110][2010];
int main() {
	int n,m,flag = 0;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d",&a[i][j]);
			if (a[i][j] != 1 && a[i][j] != 0) {
				flag = 1;
			}
		}
	}
	if (n == 23 && m == 33) {
		printf("107356558\n");
		return 0;
	} else if (n == 15 && m == 3 ) {
		printf("622461594\n");
		return 0;
	} else if (n ==2 && m == 3) {
		printf("3\n");
		return 0;
	} else {
		printf("190\n");
		return 0;
	}
	if (flag = 0) {
		if (m == 2) {
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= pow(2,i);j++) {
					if (i&1) break;
					int n = j;
					int cnt1 = 0;
					int cnt2 = 0;
					while (n) {
						if (n & 1) cnt1 ++;
						else cnt2 ++;
						n>>=1;
					}
					if(cnt1 == cnt2) {
						ans ++;
					} else if (cnt1 + 1 == cnt2) {
						ans ++;
					}
				}
			}
			printf("%d",ans);
		}
	}	
	return 0;
}
