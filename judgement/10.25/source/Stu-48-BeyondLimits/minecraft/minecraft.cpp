#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 10050;
using namespace std;
int b, n, d, m;
namespace p1 {
	int ans = 0, a[MAXN] = {0};
	bool check(int x, int y) { return a[x] + d >= a[y]; }
	void solve() {
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++) {
			int l = i + 1, r = n, res = i;
			if(l > r)
				continue;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(check(i, mid)) {
					res = mid;
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
			ans += res - i;
		}
		printf("%d\n", ans);
	}
}
namespace p2 {
	struct node {
		int x, y, z;
	}a[MAXN] = {0};
	int ans = 0;
	bool cmp(node a, node b) { return a.z < b.z; }
	bool check(int x, int y) { return abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y) >= d; }
	void mqwq1() {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= d)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	void mqwq2() {
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			int l = i + 1, r = n, res = i;
			if(l > r)
				continue;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(check(i, mid)) {
					res = mid;
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
			ans += res - i;
		}
		printf("%d\n", ans);
	}
	void solve() {
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &a[i].x, &a[i].y);
			a[i].z = a[i].x + a[i].y;
		}
		if(n <= 1000)
			mqwq1();
		else
			mqwq2();
	}
}
namespace p3 {
	struct node {
		int x, y, z;
	}a[MAXN] = {0};
	int ans = 0;
	void solve() {
		for(int i = 1; i <= n; i++)
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) + abs(a[i].z - a[j].z)<= d)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("minecraft.in", "r", stdin);
	freopen("minecraft.out", "w", stdout);
	scanf("%d %d %d %d", &b, &n, &d, &m);
	if(d > m) {
		printf("%lld\n", (1ll * n * (n - 1)) >> 1);//
		return 0;
	}
	if(b == 1)
		p1::solve();
	else if(b == 2)
		p2::solve();
	else
		p3::solve();
	return 0;
}
