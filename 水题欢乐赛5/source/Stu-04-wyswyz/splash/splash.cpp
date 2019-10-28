#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t, op, a, b, c, te;

int main() {
	freopen("splash.in", "r", stdin);
	freopen("splash.out", "w", stdout);
	scanf("%d%d", &t, &op);
	while(t--)
	{
		for(int i = 1; i <= 6; i++)
			for(int j = 1; j <= 6; j++)
			{
				if(i == 1 && j == 1)
					scanf("%d", &a);
				else if(i == 1 && j == 2)
					scanf("%d", &b);
				else if(i == 1 && j == 3)
					scanf("%d", &c);
				else scanf("%d", &te);
			}
		if(op == 2)
		{
			printf("%d", 8 + a + b + c);
			continue;
		}
		if(op == 1)
		{
			printf("%d", 5 + a + b + c);
			continue;
		}
	}
	return 0;
}
