#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 510;

int n, m, p, mp[N][N], sa[N][N], fa[N], num[N];

void init() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++) {
		sort(sa[i], sa[i] + m);
		for (int j = 0; j < m - 1; j++) {
			mp[i][j] = sa[i][j + 1] - sa[i][j];
		}
		mp[i][m - 1] = p - sa[i][m - 1] + sa[i][0];
	}
}

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool ok(int a, int b) {
	for (int i = 0; i < m; i++) {
		bool is = true;
		for (int k = 0; k < m; k++) {
			if (mp[a][k] != mp[b][(i + k) % m]) {
				is = false;
				break;
			}
		}
		if (is)
			return true;
	}
	return false;
}

void solve() {
	init();
	for (int i = 2; i <= n; i++) {
		set<int> s;
		for (int j = 1; j < i; j++) {
			if (s.count(find(j)))
				continue;
			if (ok(i, j)) {
				fa[i] = fa[j];
				break;
			}else
				s.insert(fa[i]);
		}
	}
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; i++)
		find(i);
	for (int i = 1; i <= n; i++)
		num[fa[i]]++;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1LL * num[i] * (num[i] - 1) / 2;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	while (~scanf("%d%d%d", &n, &m, &p)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &sa[i][j]);
			}
		}
		solve();
	}
	return 0;
}
