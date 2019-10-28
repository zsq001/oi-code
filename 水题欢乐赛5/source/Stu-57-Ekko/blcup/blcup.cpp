#include <stdio.h>
typedef int int_;
#define int long long
const int mod = 19260817;
int block[110][110][110],n;
void init(int n){
	for (int i = 0; i <= n; i++) {
		block[0][0][i] = 1;
		block[0][i][0] = 1;
		block[i][0][0] = 1;
	}
}
int_ main() {
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%lld",&n);
	if (n <= 100) {
		init(n);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int z = 0; z <= n; z++) {
					if ((j == i && i == 0)||(j == z && z == 0)||(i == z && z == 0)) continue;
					if (i == 0) {
						block[i][j][z] = (block[i][j-1][z] + block[i][j][z-1])%mod;
					} else if (j == 0) {
						block[i][j][z] = (block[i-1][j][z] + block[i][j][z-1])%mod;
					} else if (z == 0) {
						block[i][j][z] = (block[i-1][j][z] + block[i][j-1][z])%mod;
					} else if (j == 0 || i == 0 || z == 0 || j == n || i == n || z == n){
						block[i][j][z] = ((block[i-1][j][z] + block[i][j-1][z])%mod + block[i][j][z-1])%mod;
					}
				}
			}
		}
		printf("%lld",block[n][n][n]);
		return 0;
	}
	return 0;
}
