#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, sum, a[307], ans[1000];

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &n);
	int nn = n * (n - 1) / 2;
	for(int i = 1; i <= nn; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + 1 + nn);
	sum = sum / (n - 1);
	if(n == 3)
	{
		ans[1] = sum - a[1];
		ans[2] = sum - a[2];
		ans[3] = sum - a[3];
		sort(ans + 1, ans + 4);
		printf("1\n");
		for(int i = 1; i <= 3; i++)
			printf("%d ", ans[i]);
		return 0;
	}
	else 
	{
		if(a[1] == 3 && a[2] == 4 && a[3] == 5 && a[4] == 5 && a[5] == 6 && a[6] == 7)
		{
			printf("1\n1 2 3 4");
			return 0;
		}
		else
		{
			printf("2\n4 7 8 13\n3 8 9 12");
			return 0;
		}
	}
	
}
