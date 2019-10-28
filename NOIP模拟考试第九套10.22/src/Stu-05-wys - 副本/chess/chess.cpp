#include <cstdio>
#include <cstring>
#include <algorithm>

using  namespace std;

int n, m, flag = 1, stx, sty, cnt, step;
char ch;
int mapp[2507][2507], ncol[30], vis[2507][2507];
int nx[5] = {0, 1, -1, 0, 0}, ny[5] = {0, 0, 0, 1, -1};

void dfs(int x, int y) {
	if(flag == 2) return ;
	if(x == stx && y == sty && vis[x][y] == cnt) {
		flag = 2;
		return ;
	}
	vis[x][y] = cnt;
	for(int i = 1; i <= 4; i++) {
		int dx = x + nx[i];
		int dy = y + ny[i];
		if((step >= 3 && dx == stx && dy == sty) || (dx >= 1 && dy >= 1 && dx <= n && dy <= m && mapp[dx][dy] == mapp[x][y] && vis[dx][dy] != cnt)) {
			++step;
			dfs(dx, dy);
			--step;
		}
	}
	return ;
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("\n");
		for(int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			int nub = ch - 'A' + 1;
			mapp[i][j] = nub;
			ncol[nub]++;
			if(ncol[nub] >= 4) flag = 0; 
		}

	}
	if(flag) {
		printf("No");
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(ncol[mapp[i][j]] < 4) continue;
			stx = i, sty = j;
			++cnt, step = 0;
			dfs(i, j);
			if(flag == 2) {
				printf("Yes\n");
//				printf("%d %d\n", stx, sty);
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
