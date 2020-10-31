#include<stdio.h>
int f[500][500];
int main()
{
	int n, m; 
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	  for(int j = 1; j <= n ; j++)
	    {
	    	f[i][j] = 1000000;
	    	f[j][i] = 1000000;
	    }
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		f[u][v] = w/2;
	}
	for(int i = 1; i <= n; i++)
	//int ww = 1000000;
	for(int i = 1; i <= n;i++)
	  for(int j = 1 ; j <= n; j++)
	    {
	    	if(f[j][j+i] <  )
	    }
}
