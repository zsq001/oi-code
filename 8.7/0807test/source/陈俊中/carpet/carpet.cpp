#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,fl[1010][1010];

int main()
{	
	freopen("carpet.in ","r",stdin);
	freopen("carpet.out","w",stdout);
	int x1,x2,y1,y2;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		++fl[x1][y1];
		--fl[x2+1][y1];
		--fl[x1][y2+1];
		++fl[x2+1][y2+1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",fl[i][j]+=fl[i-1][j]+fl[i][j-1]-fl[i-1][j-1]);
		}
		printf("\n");
	}
	return 0;
}
