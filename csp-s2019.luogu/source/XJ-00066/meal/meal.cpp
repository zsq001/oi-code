#include <cstdio>
#include <algorithm>
#include <cstring>

const int mod = 998244353;

using namespace std;

int n, m, ans;
int a[10][10];

namespace work1 {
	void sub1() {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				if(j == i) continue;
				if(a[1][i] && a[2][j]) ans++;
 			}
		}
	}
}

namespace work2 {
	void sub2() {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				for(int k = 1; k <= m; k++) {
					for(int l = 1; l <= m; l++) {
						if(k == l) continue;
						if(a[i][k] && a[j][l]) ans++;
					}
				}
			}
		}
		if(m == 3) {
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					for(int k = j + 1; k <= n; k++) {
						for(int l = 1; l <= m; l++) {
							for(int u = 1; u <= m; u++) {
								for(int o = 1; o <= m; o++) {
									if(l == u || u == o || l == o) continue;
									if(a[i][l] && a[j][u] && a[k][o]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				for(int k = j + 1; k <= n; k++) {
					for(int p = k + 1; p <= n; p++) {
						for(int l = 1; l <= m; l++) {
							for(int u = 1; u <= m; u++) {
								for(int o = 1; o <= m; o++) {
									for(int t = 1; t <= m; t++) {
										if((l == u && u == o) || (l == u && u == t) || (l == t && t == o) || (t == u && u == o)) continue;
										if(a[i][l] && a[j][u] && a[k][o] && a[p][t]) ans++;
									}
								}
							}
						}
					}	
				}
			}
		}
	}
}

int main() {
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	scanf("%d%d", &n, &m);
//	in_it();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	if(n == 3) work1::sub1();
	if(n == 5) work2::sub2();
	printf("%d", ans);
	return 0;
}
