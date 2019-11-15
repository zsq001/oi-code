#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mat[1000][1000];
int n,m,k;
inline void determine(int x,int y,int p)
{
	if(x == 1)
	{
		 for(int i = 1;i <= m;i ++)
		 {
		 	mat[y][i] = p;
		 }
	}
	if(x == 2)
	{
		for(int i = 1;i <= n;i ++)
		{
			mat[i][y] = p;
		}
	}
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	memset(mat,0,sizeof(mat));
	scanf("%d %d",&n,&m);
	scanf("%d",&k);
	for(int i = 1;i <= k;i ++)
	{
		int a,b,c;
	    scanf("%d %d %d",&a,&b,&c);
		determine(a,b,c);
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
