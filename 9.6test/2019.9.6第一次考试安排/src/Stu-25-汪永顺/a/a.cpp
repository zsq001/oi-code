#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a, acnt, bcnt, ans;

void init()
{
	ans = 0;
	acnt = 0;
	bcnt = 0;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			if(a % 3 == 0) ans++;
			else
			{
				a = a % 3;
				if(a == 1) acnt++;
				else bcnt++;
			} 
		}
		if(acnt < bcnt)
		{
			ans += acnt;
			bcnt -= acnt, acnt = 0;
			ans += bcnt / 3;
		}
		else
		{
			ans += bcnt;
			acnt -= bcnt, bcnt = 0;
			ans += acnt / 3;
		}
		printf("%d\n", ans);
	}
}
