#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m, ans, x;
double h[100020], y, maxx;

int main() {
	freopen("building.in", "r", stdin);
	freopen("building.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		maxx = 0;
		scanf("%d%lf", &x, &y);
		h[x] = y;
		for(int i = 1; i <= n; i++)
		{
			if(h[i] / i <= maxx) continue;
			else ans++;
			maxx = max(maxx, h[i] / i);
		}
		printf("%d\n", ans);
		ans = 0;
	}
}
