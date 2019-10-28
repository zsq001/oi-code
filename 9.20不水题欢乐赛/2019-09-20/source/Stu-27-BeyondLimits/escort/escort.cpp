#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
const int INF = 1 << 30;
const int MAXN = 10050;
const int MAXM = 10050;
using namespace std;
int n, m, ttt, s, x, p, t, u, v, w1, w2, num, head[MAXN], dis[MAXN];
bool vis[MAXN];
struct node {
	int to, val, nextt;
}edge[MAXM];
struct node1 {
	int pos, dis;
	bool operator < (const node1 &a) const {
		return a.dis > dis;
	}
};
priority_queue<node1> q;
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
void addedge(int u, int v, int w) {
	edge[++num].to = v;
	edge[num].val = w;
	edge[num].nextt = head[u];
	head[u] = num;
}
int dij(int ss, int tt) {
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[ss] = 0;
	q.push((node1){ss, 0});
	while(!q.empty()) {
		node1 now = q.top();
		q.pop();
		int pos = now.pos;
		if(vis[pos])
			continue;
		vis[pos] = true;
		for(int i = head[pos]; i; i = edge[i].nextt) {
			int to = edge[i].to, val = edge[i].val;
			if(dis[to] > dis[x] + val) {
				dis[to] = dis[x] + val;
				if(!vis[to])
					q.push((node1){to, dis[to]});
			}
		}
	}
	return dis[tt];
}
int main() {
	freopen("escort.in", "r", stdin);
	freopen("escort.out", "w", stdout);
	n = read();
	m = read();
	ttt = read();
	s = read();
	x = read();
	if(ttt == 1) {
		p = read();
		t = read();
		for(int i = 1; i <= m; i++) {
			u = read();
			v = read();
			w1 = read();
			w2 = read();
			addedge(u, v, w1);
			addedge(v, u, w2);
		}
		cout << dij(s, p) + dij(p, t) << endl;
		return 0;
	}
	cout << "wycddl" << endl;
	return 0;
}
/*
5 6 1 1 1
4
5
1 2 1 1
2 4 2 2
4 5 6 6
1 4 5 5
1 3 5 5
3 5 1 1
*/
