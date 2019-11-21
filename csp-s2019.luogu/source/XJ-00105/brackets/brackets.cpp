#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>

std::stack <char> sta;
std::string str;
char tree[500010];
int fa[500010];
int n, s;
long long ans;

void gen(int x)
{
	str += tree[x];
	if (fa[x])	gen(fa[x]);
	return ;
}

void change(std::string &s)
{
	int len = s.size();
	for (int i = 0; i < len / 2; ++i)
		std::swap(s[i], s[len - i - 1]);
}

int cal(int l, int r)
{
	bool flag = true;
	for (int i = l; i <= r; ++i)
	{
		if (sta.empty() && str[i] == ')')
		{
			flag = false;
			break;
		}
		if (str[i] == ')')
		{
			sta.pop();
		}
		else
		{
			sta.push(str[i]);
		}
	}
	while (!sta.empty())
	{
		flag = false;
		sta.pop();
	}
	return flag ? 1 : 0;
}

int solve(std::string s)
{
	int len = s.size(), sum = 0;
	for (int i = 0; i < len; ++i)
		for (int j = i + 1; j <= len; ++j)
			sum += (cal(i, j));
	std::cout << str << " " << sum << std::endl;
	return sum;
}

int main()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		std::cin >> tree[i];
	for (int i = 2; i <= n; ++i)
		scanf("%d", &fa[i]);
	for (int i = 1; i <= n; ++i)
	{
		str = "";
		gen(i);
		change(str);
		ans ^= (solve(str) * i);
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

