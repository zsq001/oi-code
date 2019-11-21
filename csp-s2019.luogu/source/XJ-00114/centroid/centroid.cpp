#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge{
	int nxt, to;
}edge[500005];
int a[500005], head[500005], in[500005], tot, sum = 1;
void add_edge(int u, int v){
	edge[++tot].nxt = head[u];
	edge[tot].to = v;
	head[u] = tot;
}
void work(int fa, int x){
	for (int i = head[x];i;i = edge[i].nxt){
		int y = edge[i].to; if (y != fa) a[++sum] = y, work(x, y);
	}
}
int main(){
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	int T, n; scanf("%d", &T);
	while (T--){
		scanf("%d", &n); int u, v, root;
		memset(in, 0, sizeof(in)); memset(edge, 0, sizeof(edge)); memset(a, 0, sizeof(a));
		for (int i = 1;i < n;i++) scanf("%d%d", &u, &v), in[v]++, in[u]++, add_edge(u, v), add_edge(v, u);
		for (int i = 1;i <= n;i++) if (in[i] == 1) root = i;
		a[1] = root; work(0, root); int ans = 0;
		for (int i = 1;i < n;i++){
			if (i % 2) ans += a[i / 2 + 1];
			else ans += a[i / 2] + a[i / 2 + 1];
			if ((n - i) % 2) ans += a[(n - i) / 2 + 1];
			else ans += a[(n - i) / 2 + 1] + a[(n - i) / 2 + 2];
		}
		printf("%d\n", ans);
	}
	return 0;
}
