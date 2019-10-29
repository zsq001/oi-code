// Code by KSkun, 2019/10
#include <cstdio>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <queue>
#include <utility>

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

const int MAXN = 1000005;

int n, h, b, e, c[MAXN], cnt[MAXN];

int main() {
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	while (scanf("%d%d%d%d", &n, &h, &b, &e) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
		}
		std::deque<PII> q;
		for (int i = 1; i <= n; i++) {
			while (!q.empty() && q.back().first >= c[i]) q.pop_back();
			q.push_back(PII(c[i], i));
			while (!q.empty() && i - q.front().second >= h) q.pop_front();
			cnt[q.front().second]++;
		}
		for (int i = b; i <= e; i++) {
			printf("%d ", cnt[i]);
		}
		puts("");
	}
	return 0;
}