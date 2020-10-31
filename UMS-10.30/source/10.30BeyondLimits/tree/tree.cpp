#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 100050;
using namespace std;
int n, m, u, v, a, num, ans, opt, x, val[MAXN], head[MAXN];
bool flag;
struct node {
	int to, nextt;
}edge[MAXN << 1];
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
void addedge(int u, int v) {
	edge[++num].to = v;
	edge[num].nextt = head[u];
	head[u] = num;
}
void dfs(int x, int last) {
	val[x] += a;
	for(int i = head[x]; i; i = edge[i].nextt) {
		int to = edge[i].to;
		if(to == last)
			continue;
		dfs(to, x);
	}
}
void dfs1(int x, int y, int last) {
	if(x == 1) {
		ans = y;
		flag = true;
		return ;
	}
	for(int i = head[x]; i && !flag; i = edge[i].nextt) {
		int to = edge[i].to;
		if(to == last)
			continue;
		dfs1(to, y + val[to], x);
	}
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; i++)
		val[i] = read();
	for(int i = 1; i < n; i++) {
		u = read();
		v = read();
		addedge(u, v);
		addedge(v, u);
	}
	for(int i = 1; i <= m; i++) {
		opt = read();
		x = read();
		if(opt == 1) {
			a = read();
			val[x] += a;
		}
		else if(opt == 2) {
			a = read();
			dfs(x, 0);
		}
		else {
			dfs1(x, val[x], 0);
			cout << ans << endl;
			ans = 0;
			flag = false;
		}
	}
	return 0;
}
