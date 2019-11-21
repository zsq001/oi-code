#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>

std::string str[15][2000];
int n;
long long k;

int Pow(int x)
{
	int sum = 1;
	for (int i = 1; i <= x; ++i)
		sum *= 2;
	return sum;
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	str[1][1] = '0';
	str[1][2] = '1';
	for (int i = 2; i <= n; ++i)
	{
		int max = Pow(i);
		for (int j = 1; j <= max / 2; ++j)
			str[i][j] = '0' + str[i - 1][j];
		for (int j = max / 2 + 1; j <= max; ++j)
			str[i][j] = '1' + str[i - 1][max + 1 - j];
	}
	std::cout << str[n][k + 1] << std::endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
