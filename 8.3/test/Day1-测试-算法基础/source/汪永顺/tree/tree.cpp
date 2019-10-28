#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
typedef int int_;
#define int long long

using namespace std;

int n, ans;

int_ main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%lld", &n);
	while(n)
	{
		n >>= 1;
		ans++;
	}
	printf("%lld", ans);
	return 0;
}
