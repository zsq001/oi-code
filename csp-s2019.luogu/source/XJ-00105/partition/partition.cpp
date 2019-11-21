#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

template <class T>
inline void read(T &x)
{
	x = 0;
	int f = 0;
	char ch = getchar();
	while (!isdigit(ch))	{ f |= (ch == '-'); ch = getchar(); }
	while (isdigit(ch))		{ x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	x = f ? -x : x;
	return ;
}

const int inf = 0x7f7f7f7f;

int a[500010], p[100010], l[100010], r[100010], b[100010];
int n, type, x, y, z, m, ans = inf;
bool flag = false;

void dfs(int now, int lastans, int sum, int s)
{
	if (now > n)
	{
		if (s < lastans)	return ;
		ans = std::min(ans, sum + s * s);
		return ;
	}
	if (s + a[now] >= lastans)
	{
		dfs(now + 1, s + a[now], sum + (s + a[now]) * (s + a[now]), 0);
	}
	dfs(now + 1, lastans, sum, s + a[now]);
}

int main()
{
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	read(n), read(type);
	if (type)
	{
		read(x), read(y), read(z), read(b[1]), read(b[2]), read(m);
		for (int i = 1; i <= m; ++i)
			read(p[i]), read(l[i]), read(r[i]);
		if (n > 2)
		{
			for (int i = 3; i <= n; ++i)
				b[i] = (x * b[i - 1] + y * b[i - 2] + z) % (2 << 29);
			for (int j = 1; j <= m; ++j)
				for (int i = p[j - 1] + 1; i <= p[j]; ++i)
					a[i] = (b[i] % (r[j] = l[j] + 1)) + l[j];
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			read(a[i]);
	}
	dfs(1, 0, 0, 0);
	std::cout << ans << std::endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

