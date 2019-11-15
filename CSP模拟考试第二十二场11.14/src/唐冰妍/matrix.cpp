#include<stdio.h>
int n, m, q, x, y, z;
int map[10001][10001] = {0};
int main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= q; i++)
	  {
	  	scanf("%d%d%d", &x, &y, &z);
	  	if(x == 1)
	  	  for(int j = 1; j <= m; j++)
	  	    map[y][j] = z;
	  	if(x == 2)
	  	  for(int j = 1; j <= n; j++)
	  	    map[j][y] = z;    
}
	for(int i = 1; i <= n; i++)
	  {
	    for(int j = 1; j <= m; j++)
	      printf("%d ", map[i][j]);
	    printf("\n");  
      }
      return 0;
}
