#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define db double

using namespace std;

int n;

struct node {
	int x, y;
}a[10];

db cha[10], dp[10][2];

void sss(int t)
{
	db x = (a[t].x - a[t - 1].x) * (a[t].x - a[t - 1].x);
	db y = (a[t].y - a[t - 1].y) * (a[t].y - a[t - 1].y);
	cha[t] = sqrt(x + y);
}

int main() {
	freopen("protect.in", "r", stdin);
	freopen("protect.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d%d", &a[1].x, &a[1].y);
	cha[0] = 1000000009;
	cha[n + 1] = 1000000009;
	for(int i = 2; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		sss(i);
	}
	dp[1][1] = cha[2] * cha[2];
	dp[1][0] = 0;
	for(int i = 2; i <= n; i++) {
		int r = min(cha[i], cha[i + 1]);
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + r * r;
	}
	printf("%.2lf", max(dp[n][1], dp[n][0]));
	return 0;
}
