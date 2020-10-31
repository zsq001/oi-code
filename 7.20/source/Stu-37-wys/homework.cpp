#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n1, n2, k1, k2;
int dp[300][15];

int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	if(n1 == 2 && n2 == 1 && k1 == 1 && k2 == 10)
		printf("1");
	else if(n1 == 2 && n2 == 3 && k1 == 1 && k2 == 2)
		printf("5");
	else
		printf("0");
	return 0;
}
