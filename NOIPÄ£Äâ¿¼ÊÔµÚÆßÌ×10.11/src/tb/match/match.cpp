#include<stdio.h>
int n, m, x, y;
int a[1000001], b[1000001];
int ans = 0;
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; i++)
	  scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
	  scanf("%d", &b[i]);
	for(int i = 1, j = 1; i <= n && j <= m; i++)
	{
		while(b[i] > a[j] + y && j < n)
		  j++;
		if(b[i] >= a[j]-x && j < n)
		  ans++, j++;  
	}  
	printf("%d\n", ans);
	return 0;
}
