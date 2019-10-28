#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
const int MAXN = 2050;
const int INF = 1e6 ;
using namespace std;
struct node {
	int u, v, w;
}f[MAXN][MAXN];
int n, kk, u, v, w, ans;
set<int> s;
vector<node> vec;
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
	bool cmp(node a, node b) { return a.w < b.w; }
	void solve() {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				f[i][j].w = INF;
		}
		for(int i = 1; i <= n - 1; i++) {
			u = read();
			v = read();
			w = read();
			f[u][v].u = f[v][u].v = u;
			f[u][v].v = f[v][u].u = v;
			f[u][v].w = f[v][u].w = w;
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++)
					f[i][j].w = min(f[i][j].w, f[i][k].w + f[k][j].w);
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				vec.push_back(f[i][j]);
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		for(int i = 0; i < (int)vec.size(); i++) {
			node p = vec[i];
			s.insert((int)p.u);
			s.insert((int)p.v);
			ans += p.w;
			int o = (int)s.size();
			if(o == kk) {
				cout << ans << endl;
				return ;
			}
		}
	}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	kk = read();
	solve();
	return 0;
}
