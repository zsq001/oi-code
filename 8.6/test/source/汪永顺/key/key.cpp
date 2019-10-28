#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#define maxn 100011

using namespace std;

int ans[maxn], bns, cnt, a[maxn], now;

int main() {
	freopen("key.in", "r", stdin);
	freopen("key.out", "w", stdout);
	char t;
	while(~scanf("%c", &t) && (t == '1' || t == '0'))
	{
		if(t == '0')
			a[++cnt] = 0;
		else if(t == '1')
			a[++cnt] = 1;
		if(a[cnt] != a[cnt - 1] && cnt != 1)
			now++;
	}
	now++;
	int n = cnt / 3;
	if(now >= n * 2)
	{
		printf("0");
		return 0;
	}
	int p = 0;
	if(cnt == 3)
	{
		printf("1\n1");
		return 0;
	}
	for(int i = 4; i <= cnt; i++)
	{
		if(now >= n * 2) break;
		if((a[i - 3] && a[i - 2] && !a[i - 1] && !a[i]) || (!a[i - 3] && !a[i - 2] && a[i - 1] && a[i]))
		{
			a[i - 2] = a[i - 2] ^ 1;
			a[i - 1] = a[i - 1] ^ 1;
			now += 2;
			ans[i - 2] = 1;
			bns++;
		}
		if(a[i - 3] == a[i - 2] && a[i - 1] == a[i] && a[i - 2] == a[i - 1])
		{
			a[i - 2] = a[i - 2] ^ 1;
			a[i - 1] = a[i - 1] ^ 1;
			now += 2;
			ans[i - 2] = 1;
			bns++;
		}
	}
	printf("%d\n", bns);
	for(int i = 1; i <= 3 * n; i++)
		if(ans[i])
			printf("%d ", i);
	return 0;
}
