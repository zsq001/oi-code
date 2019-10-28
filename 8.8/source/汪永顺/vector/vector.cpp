#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int t, a, b, c, d, x, y;

inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main() {
	freopen("vector.in", "r", stdin);
	freopen("vector.out", "w", stdout);
	scanf("%d", &t);
	if(t % 2 == 1)
		printf("N\n");
	t = t - (t % 2);
	while(t -= 2 >= 0)
	{
		printf("Y\n");
		printf("N\n");
	}
	return 0;
}
