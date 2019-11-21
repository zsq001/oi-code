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

int a[110][2010];
int l[2010];
int n, m, ans;

void dfs(int now, int k)
{
	if (now > n)
	{
		if (k < 2)	return ;
		for (int i = 1; i <= m; ++i)
			if (l[i] > k / 2)
				return ;
		++ans;
		return ;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j <= a[now][m]; ++j)
		{
			l[i] += j;
			dfs(now + 1, k + j);
			l[i] -= j;
		}
	}
}

int main()
{
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a[i][j]);
	dfs(1, 0);
	std::cout << ans / 2 % 998244353 << std::endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

