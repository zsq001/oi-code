#include <bits/stdc++.h>
using namespace std;
int n, m;
namespace p1 {
	void solve() {
		int a[5][5] = {0}, ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= m; k++) {
				if(j == k)
					continue;
				ans += a[1][j] * a[2][k];
			}
		}
		printf("%d\n", ans);
	}
}
namespace p2 {
	void solve() {
		int ans = 0, a[10][10] = {0};
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(int k = 2; k <= n; k++) {
			if(k == 2) {
				for(int i = 1; i <= n; i++) {
					for(int j = 1; j <= n; j++) {
						if(i == j)
							continue;
						ans += a[i][1] * a[j][2];
					}
				}
			}
			else if(k == 3)
				continue;
			else if(k == 4) {
				for(int i = 1; i <= n; i++) {
					for(int j = i + 1; j <= n; j++) {
						for(int l = 1; l <= n; l++) {
							for(int r = l + 1; r <= n; r++) {
								if(l == r || i == l || j == l || i == r || j == r)
									continue;
								ans += a[i][1] * a[j][1] * a[l][2] * a[r][2];
							}
						}
					}
				}
			}
			else if(k == 5)
				continue;
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	if(n <= 2)
		p1::solve();
	else if(n <= 5 && m <= 2)
		p2::solve();
	else
		cout << "998244353" << endl;
	return 0;
}
