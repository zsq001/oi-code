#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 100050;
using namespace std;
struct node {
	int x, y;
}a[MAXN];
int n, h, b, e, x, cnt[MAXN];
bool vis[MAXN];
bool cmp(node a, node b) { return a.y == b.y ? a.x > b.x : a.y < b.y; }
void init() {
	memset(a, 0, sizeof(a));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
}
int main() {
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	while(scanf("%d %d %d %d", &n, &h, &b, &e) == 4) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			a[i] = (node){i, x};
		}
		int pos = (b - h) > 0 ? b - h : 1;
		sort(a + pos, a + n + 1, cmp);
		for(int i = 1; i <= e - pos + 1; i++) {
			int p, q;
			p = a[i].x;
			if(!vis[p]) {
				vis[p] = true;
				cnt[p]++;
			}
			q = p + 1;
			for(int j = 1; j <= h; j++) {
				if(vis[q]) {
					q++;
					continue;
				}
				if(q == n + 1)
					break;
				cnt[p]++;
				vis[q] = true;
				q++;
			}
		}
		for(int i = b; i <= e; i++)
			printf("%d ", cnt[i]);
		printf("\n");
		init();
	}
	return 0;
}
