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

int L, C, cnt;
int tmp;
char s[35], b[35];

void dfs(const int k, const int l) {
	if (k > L) {
		if (tmp >= 1 && L - tmp >= 2) {
			++cnt;
			printf("%s\n", b + 1);
			if (cnt >= 25000)
				exit(0);
		}
		return ;
	}
	b[k] = s[l];
	if (b[k] == 'a' || b[k] == 'e' || b[k] == 'i' || b[k] == 'o' || b[k] == 'u')
		++tmp;
	dfs(k + 1, l + 1);
	if (b[k] == 'a' || b[k] == 'e' || b[k] == 'i' || b[k] == 'o' || b[k] == 'u')
		--tmp;
	b[k] = 0;
	if (C - l + 1 > L - k + 1)
		dfs(k, l + 1);
}

int main() {
//	freopen("in", "r", stdin);
	freopen("ticket.in", "r", stdin);
	freopen("ticket.out", "w", stdout);
	L = in(), C = in();
	for (int i = 1; i <= C; ++i) {
		scanf(" %c", &s[i]);
		if (s[i] < 97)
			s[i] += 32;
	}
	std::sort(s + 1, s + 1 + C);
	dfs(1, 1);
	return 0;
}
