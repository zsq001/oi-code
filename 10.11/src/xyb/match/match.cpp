#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010], b[100010];
int n, m, x, y;
int ans;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int j = 1; j <= m; ++j) scanf("%d", &b[j]);
	int i = 1, j = 1;
	while (true) {
		if (i > n || j > m) break;
		if (a[i] - x <= b[j] && a[i] + y >= b[j]) {
			ans++;
			i++;
			j++;
		}
		else if (a[i] - x > b[j]) j++;
		else i++;
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
