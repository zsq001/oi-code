#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
const int INF = 1 << 30;
const int MAXN = 1050;
const int dirx[] = {1, 0, 0, -1};
const int diry[] = {0, 1, -1, 0};
using namespace std;
struct node {
	int x, y, t;
};
queue<node> q;
struct node1{
	int x, y;
}p[MAXN << 1];
int t, n, x, y, tmax = INF;
bool vis[MAXN][MAXN];
int read (){
	int xx = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		xx = (xx << 1) +(xx << 3) + (alpha ^48);
		alpha = getchar();
	}
	return sign ? -xx : xx;
}
bool check(int x, int y) { return x < 1 || x > n || y < 1 || y > n; }
bool bfs() {
	int nowt = 0;
	q.push((node){1, 1, 0});
	vis[1][1] = true;
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		int x = now.x, y = now.y, t = now.t;
		if(t != nowt) {
			vis[p[t].x][p[t].y] = true;
			nowt = t;
		}
		if(x == n && y == n)
			return true;
		else if(vis[n][n] && t == tmax)
			return false;
		for(int i = 0; i < 4; i++) {
			int dx = x + dirx[i], dy = y + diry[i];
			if(check(dx, dy) || vis[dx][dy] || (dx == p[t + 1].x && dy == p[t + 1].y && (dx != n && dy != n)))
				continue;
			vis[dx][dy] = true;
			q.push((node){dx, dy, t + 1});
		}
	}
	return false;
}
void init() {
	tmax = INF;
	while(!q.empty())
		q.pop();
	for(int i = 1; i <= n; i++) {
		p[i].x = p[i].y = 0;
		for(int j = 1; j <= n; j++)
			vis[i][j] = false;
	}
}
int main() {
	freopen("bar.in", "r", stdin);
	freopen("bar.out", "w", stdout);
	t = read();
	while(t--) {
		n = read();
		for(int i = 1; i <= (n << 1) - 2; i++) {
			x = read();
			y = read();
			if(x == n && y == n && tmax == INF)
				tmax = i;
			p[i].x = x;
			p[i].y = y;
		}
		bfs() ? printf("Yes\n") : printf("No\n");
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
