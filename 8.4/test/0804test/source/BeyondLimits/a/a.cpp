#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>
const int MAXN = 200050;
const int MAXM = 2100000;
using namespace std;
set<int> s;
bool vis[MAXN];
int n, m, num, cnt, cnt1, ans, o[MAXN][3], fa[MAXN], head[MAXN];
struct Edge {
	int u, to, val, nextt;
}edge[MAXM];
struct node {
	int x, y;
}a[MAXN];
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
bool cmp(Edge a, Edge b) { return a.val > b.val; }
void addedge(int u, int v, int w) {
	edge[++num].u = u;
	edge[num].to = v;
	edge[num].val = w;
	edge[num].nextt = head[u];
	head[u] = num;
}
int findd(int x) {
	int t = x, pre;
	while(t != fa[t])
		t = fa[t];
	while(x != t) {
		pre = fa[x];
		fa[x] = t;
		x = pre;
	}
	return t;
}
void kruscal() {
	int cnt1 = 0;
	for(int i = 0; i < n; i++)
		fa[i] = i;
	for(int i = 1; i <= num; i++) {
		int u = edge[i].u, v = edge[i].to;
		if(vis[u] || vis[v])
			continue;
		int fx = findd(u), fy = findd(v);
		if(fx == fy)
			continue;
		vis[o[u][1]] = vis[o[u][2]] = vis[o[v][1]] = vis[o[v][2]] = true;
		fa[fx] = fa[fy];
		s.insert(u);
		s.insert(v);
		++cnt1;
		if(cnt1 == m - 1)
			return;
	}
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	n = read();
	m = read();
	if(m > (n >> 1)) {
		cout << "Error!" << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) {
		a[i].x = read();
		a[i].y = i;
	}
	o[0][1] = n - 1;
	o[0][2] = 1;
	for(int i = 1; i < n - 1; i++) {
		o[i][1] = i - 1;
		o[i][2] = i + 1;
	}
	o[n - 1][1] = n - 2;
	o[n - 1][2] = 0;
	for(int i = 2; i <= n - 2; i++)
		addedge(0, i, a[0].x + a[i].x);
	for(int i = 1 ; i < n; i++) {
		for(int j = i + 2; j <= n - 1; j++)
			addedge(i, j, a[i].x + a[j].x);
	}
	//cout << num << endl;
	sort(edge + 1, edge + num + 1, cmp);
	kruscal();
	for(set<int>:: iterator it = s.begin(); it != s.end(); it++) {
		int pos = *it;
		ans += a[pos].x;
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
