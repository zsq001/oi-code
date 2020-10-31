#include <cstdio>
#include <cstring>
#include <algorithm>
int in() {
	int x = 0; char c = getchar(); bool f = 0;
	while (c < '0' || c > '9')
		f |= c == '-', c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 55;

int n, m, sx, sy, tx, ty;
char mp[N][N];
bool vis[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool dfs(const int x, const int y) {
	if (x == tx && y == ty)
		return 1;
	vis[x][y] = 1;
	for (int i = 0, ux, uy; i < 4; ++i) {
		ux = x + dx[i], uy = y + dy[i];
		if (!vis[ux][uy] && mp[ux][uy] == mp[x][y] && dfs(ux, uy))
			return 1;
	}
	vis[x][y] = 0;
	return 0;
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	n = in(), m = in();
	for (int i = 1; i <= n; ++i)
		scanf(" %s", mp[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			vis[i][j] = 1;
			for (int x = 0; x < 3; ++x) {
				for (int y = x + 1; y < 4; ++y) {
					sx = i + dx[x], sy = j + dy[x];
					tx = i + dx[y], ty = j + dy[y];
					if (mp[sx][sy] == mp[i][j] && mp[tx][ty] == mp[i][j] && dfs(sx, sy))
						return puts("Yes"), 0;
				}
			}
			vis[i][j] = 0;
		}
	}
	puts("No");
	return 0;
}
