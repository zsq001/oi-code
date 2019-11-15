#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, q;
int x[1000007], y[1000007], z[1000007];
int mapp[1007][1007], visx[1007], visy[1007];

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for(register int i = 1; i <= q; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}
	for(register int i = q; i >= 1; i--) {
		if(x[i] == 1) {
			if(visx[y[i]]) continue;
			visx[y[i]] = 1;
			for(register int j = 1; j <= m; j++) {
				if(mapp[y[i]][j] == 0)
					mapp[y[i]][j] = z[i];
			}
		}
		else if(x[i] == 2) {
			if(visy[y[i]]) continue;
			visy[y[i]] = 1;
			for(register int j = 1; j <= n; j++) {
				if(mapp[j][y[i]] == 0)
					mapp[j][y[i]] = z[i];
			}
		}
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) {
			printf("%d ", mapp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
