#include <cstdio>
#include <cstring>
#include <algorithm>
int in() {
	int x = 0; char c = getchar(); bool f = 0;
	while (c < '0' || c > '9')
		f |= c == '-', c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 2e5 + 5;

int n, m;

struct info {
	long long x, y, z, res;
} ;
struct segment_tree {
	long long min[N << 2], max[N << 2], t[N << 2];
	int a[N << 2], d[N << 2];
	bool tag[N << 2];
	inline void push_up(const int p) {
		min[p] = min[p << 1], chk_min(min[p], min[p << 1 | 1]);
		max[p] = max[p << 1], chk_min(max[p], max[p << 1 | 1]);
		t[p] = max[p << 1 | 1] - min[p << 1];
		chk_max(t[p], t[p << 1]), chk_max(t[p], t[p << 1 | 1]), chk_max(t[p], 0ll);
	}
	inline void spread(const int p, const int tl, const int tr, const int mid) {
		if (d[p] >= 0) {
			min[p << 1] = a[p];
			max[p << 1] = 1ll * (mid - tl) * d[p] + a[p];
			t[p << 1] = max[p << 1] - min[p << 1];
		} else {
			min[p << 1] = 1ll * (mid - tl) * d[p] + a[p];
			max[p << 1] = a[p];
			t[p << 1] = 0;
		}
		d[p << 1] = d[p], a[p << 1] = a[p];
		if (d[p] >= 0) {
			min[p << 1 | 1] = 1ll * (mid + 1 - tl) * d[p] + a[p];
			max[p << 1 | 1] = 1ll * (tr - tl) * d[p] + a[p];
			t[p << 1 | 1] = max[p << 1 | 1] - min[p << 1 | 1];
		} else {
			min[p << 1 | 1] = 1ll * (tr - tl) * d[p] + a[p];
			max[p << 1 | 1] = 1ll * (mid + 1 - tl) * d[p] + a[p];
			t[p << 1 | 1] = 0;
		}
		d[p << 1 | 1] = d[p], a[p << 1 | 1] = 1ll * (mid + 1 - tl) * d[p] + a[p];
		tag[p] = 0;
		tag[p << 1] = tag[p << 1 | 1] = 1;
	}
	void build(int tl = 1, int tr = n, int p = 1) {
		if (tl == tr)
			return (void)(min[p] = max[p] = in());
		int mid = (tl + tr) >> 1;
		build(tl, mid, p << 1), build(mid + 1, tr, p << 1 | 1);
		push_up(p);
	}
	void modify(int l, int r, int x, int y, int tl = 1, int tr = n, int p = 1) {
		if (l <= tl && tr <= r) {
			if (y >= 0) {
				min[p] = 1ll * (tl - l) * y + x;
				max[p] = 1ll * (tr - l) * y + x;
				t[p] = max[p] - min[p];
			} else {
				min[p] = 1ll * (tr - l) * y + x;
				max[p] = 1ll * (tl - l) * y + x;
				t[p] = 0;
			}
			a[p] = 1ll * (tl - l) * y + x;
			d[p] = y;
			tag[p] = 1;
			return ;
		}
		int mid = (tl + tr) >> 1;
		if (tag[p])
			spread(p, tl, tr, mid);
		if (mid >= l)
			modify(l, r, x, y, tl, mid, p << 1);
		if (mid < r)
			modify(l, r, x, y, mid + 1, tr, p << 1 | 1);
		push_up(p);
	}
	info query(int l, int r, int tl = 1, int tr = n, int p = 1) {
		if (l <= tl && tr <= r)
			return (info){min[p], max[p], t[p], t[p]};
		int mid = (tl + tr) >> 1;
		if (tag[p])
			spread(p, tl, tr, mid);
		if (mid < l)
			return query(l, r, mid + 1, tr, p << 1 | 1);
		if (mid >= r)
			return query(l, r, tl, mid, p << 1);
		info t1, t2;
		t1 = query(l, r, tl, mid, p << 1);
		t2 = query(l, r, mid + 1, tr, p << 1 | 1);
		chk_max(t1.z, t2.z), chk_max(t1.z, t2.y - t1.x);
		chk_min(t1.x, t2.x), chk_max(t1.y, t2.y);
		return t1;
	}
} T;

namespace small_n {
	long long a[N], f[N];
	int main() {
		for (int i = 1; i <= n; ++i)
			a[i] = in();
		while (m--) {
			if (in() == 1) {
				int l = in(), r = in();
				long long tmp;
				if (l == r) {
					puts("0");
					continue;
				}
				f[l] = 0, tmp = -a[l];
				for (int i = l + 1; i <= r; ++i)
					f[i] = f[i - 1], chk_max(f[i], a[i] + tmp), chk_max(tmp, f[i - 1] - a[i]);
				printf("%lld\n", f[r]);
			} else {
				int l = in(), r = in(), x = in(), y = in();
				for (int i = l; i <= r; ++i)
					a[i] = 1ll * (i - l) * y + x;
			}
		}
		return 0;
	}
}

int main() {
	//freopen("in", "r", stdin);
	freopen("gem.in", "r", stdin);
	freopen("gem.out", "w", stdout);
	n = in(), m = in();
	if (n <= 5000 && m <= 5000) {
		small_n::main();
		return 0;
	}
	T.build();
	while (m--) {
		if (in() == 1) {
			int l = in(), r = in();
			printf("%lld\n", T.query(l, r).res);
		} else {
			int l = in(), r = in(), x = in(), y = in();
			T.modify(l, r, x, y);
		}
	}
	return 0;
}
