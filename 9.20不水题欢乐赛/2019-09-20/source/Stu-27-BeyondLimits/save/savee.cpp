bool check(int x, int y) {
	int cntt = 0;
	cntt += b[x - 1][y];
	cntt += b[x + 1][y];
	cntt += b[x][y - 1];
	cntt += b[x][y + 1];
	return cntt >= 2;
}
void dfs(int x, int y, int step) {
	bool flag1 = false;
	if(flag2)
		return ;
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			if(b[i][j] == 1) {
				flag1 = true;
				break;
			}
		}
		if(flag1)
			break;
	}
	if(!flag1) {
		cnt = step;
		flag2 = true;
		return ;
	}
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			if(b[i][j] && !vis[i][j] && check(i, j)) {
				vis[i][j] = true;
				if(i > 1)
					b[i - 1][j] ^= 1;
				if(i < 5)
					b[i + 1][j] ^= 1;
				if(j > 1)
					b[i][j - 1] ^= 1;
				if(j < 5)
					b[i][j + 1] ^= 1;
				b[i][j] ^= 1;
				dfs(i, j, step + 1);
				vis[i][j] = false;
				if(i > 1)
					b[i - 1][j] ^= 1;
				if(i < 5)
					b[i + 1][j] ^= 1;
				if(j > 1)
					b[i][j - 1] ^= 1;
				if(j < 5)
					b[i][j + 1] ^= 1;
				b[i][j] ^= 1;
			}
		}
	}
}
void init() {
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++)
			b[i][j] = a[i][j];
	}
	memset(vis, false, sizeof(vis));
}
int solve() {
	bool ww = false;
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			if(a[i][j]) {
				ww = true;
				break;
			}
		}
		if(ww)
			break;
	}
	if(!ww)
		return 0;
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			if(a[i][j] == 1) {
				init();
				vis[i][j] = true;
				b[i - 1][j] ^= 1;
				b[i + 1][j] ^= 1;
				b[i][j - 1] ^= 1;
				b[i][j + 1] ^= 1;
				b[i][j] ^= 1;
				dfs(i, j, 1);
				if(flag2)
					return cnt;
			}
		}
	}
	return -1;
}
