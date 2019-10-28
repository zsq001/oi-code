#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#define maxn 2005

using namespace std;

int n, m, xx1, yy1, xx2, yy2, t, sum[maxn][maxn];

int main() {
	freopen("carpet.in", "r", stdin);
	freopen("carpet.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
		sum[xx1][yy1]++;
		sum[xx2 + 1][yy2 + 1]++;
		sum[xx1][yy2 + 1]--;
		sum[xx2 + 1][yy1]--;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%d ", sum[i][j]);
		}
		puts("");
	}
	return 0;
}
