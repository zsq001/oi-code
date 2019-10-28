// Code by KSkun, 2019/10
#include <cstdio>
#include <cctype>

#include <algorithm>
#include <utility>
#include <functional>

typedef long long LL;
typedef std::pair<int, int> PII;

inline char fgc() {
	static char buf[1000005], * p1 = buf, * p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000005, stdin), p1 == p2)
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

int n;
PII p[MAXN];

int main() {
	freopen("physics.in", "r", stdin);
	freopen("physics.out", "w", stdout);
	n = readint();
	for (int i = 1; i <= n; i++) {
		p[i] = {readint(), readint()};
	}
	double ans = 0, v = 0;
	for (int i = 1; i <= n; i++) {
		ans += v * p[i].second + 0.5 * p[i].first * p[i].second * p[i].second;
		v += p[i].first * p[i].second;
	}
	std::sort(p + 1, p + n + 1, std::greater<PII>());
	double ans1 = ans;
	ans = 0; v = 0;
	for (int i = 1; i <= n; i++) {
		ans += v * p[i].second + 0.5 * p[i].first * p[i].second * p[i].second;
		v += p[i].first * p[i].second;
	}
	printf("%.1lf", ans - ans1);
	return 0;
}