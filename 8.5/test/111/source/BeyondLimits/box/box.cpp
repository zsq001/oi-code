#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int INF = 1 << 30;
const int MAXN = 1050;
using namespace std;
int n, t, ans = -INF, a[MAXN];
bool vis[MAXN];
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
void dfs1(int step, int l, int r, int x, int y) {
	if(r < l) {
		if(step == n + 1)
			ans = max(ans, x - y);
		return ;
	}
	if(l < 0 || l > n || r < 0 || r > n)
		return ;
	if(step & 1) {
		if(!vis[l]) {
			vis[l] = true;
			dfs1(step + 1, l + 1, r, x + a[l], y);
			vis[l] = false;
		}
		if(!vis[r]) {
			vis[r] = true;
			dfs1(step + 1, l, r - 1, x + a[r], y);
			vis[r] = false;
		}
	}
	else {
		if(!vis[l]) {
			vis[l] = true;
			dfs1(step + 1, l + 1, r, x, y + a[l]);
			vis[l] = false;
		}
		if(!vis[r]) {
			vis[r] = true;
			dfs1(step + 1, l , r - 1, x, y + a[r]);
			vis[r] = false;
		}
	}
}
void init() {
	ans = -INF;
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i++)
		a[i] = 0;
}
int main() {
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	t = read();
	while(t--) {
		n = read();
		for(int i = 1; i <= n; i++)
			a[i] = read();
		dfs1(1, 1, n, 0, 0);
		printf("%d\n", ans);
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
