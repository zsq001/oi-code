#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, p, poi[507][507], vis[507][507], cnt;

int main() {
	freopen("plate.in", "r", stdin);
	freopen("plate.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &poi[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				for(int l = k + 1; l <= m; l++) {
					for(int p = 1; p <= m; p++) {
						for(int o = p + 1; o <= m; o++) {
							if(poi[i][l] - poi[i][k] == poi[j][o] -poi[j][p] && vis[i][j] == 0) {
								cnt++;
								vis[i][j] = 1;
							}
						}
					}
				}
			}
		}
	}
	printf("%d", cnt * 2);
	return 0;
}
