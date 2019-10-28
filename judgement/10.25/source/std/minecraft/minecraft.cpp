// Code by KSkun, 2019/10
#include <cstdio>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <vector>

typedef long long LL;

inline char fgc() {
	static char buf[100000], * p1 = buf, * p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
		? EOF : *p1++;
}

inline LL readint() {
	LL res = 0, neg = 1; char c = fgc();
	for(; !isdigit(c); c = fgc()) if(c == '-') neg = -1;
	for(; isdigit(c); c = fgc()) res = res * 10 + c - '0';
	return res * neg;
}

inline char readsingle() {
	char c;
	while(!isgraph(c = fgc())) {}
	return c;
}

const int MAXN = 100005;

int B, n, D, m;
int sum[80][505][505];

class BinaryIndexedTree {
private:
	inline static int lowbit(int x) {
		return x & -x;
	}
	int N;
	std::vector<int> dat;
public:
	BinaryIndexedTree(int _N = 240) {
		N = _N;
		dat.assign(N, 0);
	}
	void add(int pos, int value) {
		for (int i = pos; i < N; i += lowbit(i)) {
			dat[i] += value;
		}
	}
	int query(int pos) {
		if (pos <= 0) return 0;
		int res = 0;
		for (int i = pos; i > 0; i -= lowbit(i)) {
			res += dat[i];
		}
		return res;
	}
	void clear() {
		dat.clear();
		dat.assign(N, 0);
	}
};

struct Pos {
	int x, y, z;
	Pos(int _x = 0, int _y = 0, int _z = 0): x(_x), y(_y), z(_z) {}
	inline bool operator<(const Pos& rhs) const {
		return z != rhs.z ? z < rhs.z : (x != rhs.x ? x < rhs.x : y < rhs.y);
	}
} pos[MAXN];

int main() {
	freopen("minecraft.in", "r", stdin);
	freopen("minecraft.out", "w", stdout);
	B = readint(); n = readint(); D = readint(); m = readint();
	for (int i = 1, x, y; i <= n; i++) {
		x = readint();
		if (B >= 2) y = readint();
		if (B >= 3) pos[i].z = readint();
		
		// coordinate transfer
		if (B >= 2) {
			pos[i].x = x + y;
			pos[i].y = x - y + m;
		} else {
			pos[i].x = x;
		}
	}
	std::sort(pos + 1, pos + n + 1);

	LL ans = 0;
	if (B == 1) {
		int lft = 1;
		for (int i = 1; i <= n; i++) {
			lft = std::lower_bound(pos + lft, pos + i, Pos(pos[i].x - D)) - pos;
			ans += i - lft;
		}
	} else if (B == 2) {
		BinaryIndexedTree bit(225005); int lst = 1;
		bit.add(pos[1].y, 1);
		for (int i = 2; i <= n; i++) {
			while (lst < i && pos[i].x - pos[lst].x > D) {
				bit.add(pos[lst].y, -1);
				lst++;
			}
			int l = std::max(0, pos[i].y - D), r = std::min(m * 2, pos[i].y + D);
			int res = bit.query(r) - bit.query(l - 1);
			ans += res;
			bit.add(pos[i].y, 1);
		}
	} else {
		D = std::min(D, m * 3);
		for (int i = 1; i <= n; i++) {
			sum[pos[i].z][pos[i].x][pos[i].y]++;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j < 505; j++) {
				for (int k = 1; k < 505; k++) {
					sum[i][j][k] += sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i][j - 1][k - 1];
				}
			}
		}
		LL ans2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = std::max(1, pos[i].z - D); j < pos[i].z; j++) {
				int d = D - (pos[i].z - j); auto arr = sum[j];
				int x1 = std::max(1, pos[i].x - d), y1 = std::max(1, pos[i].y - d), x2 = pos[i].x + d, y2 = pos[i].y + d;
				ans += arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
			}
			auto arr = sum[pos[i].z];
			int x1 = std::max(1, pos[i].x - D), y1 = std::max(1, pos[i].y - D), x2 = pos[i].x + D, y2 = pos[i].y + D;
			ans2 += arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
		}
		ans2 -= n;
		ans += ans2 / 2;
	}

	printf("%lld", ans);
	return 0;
}