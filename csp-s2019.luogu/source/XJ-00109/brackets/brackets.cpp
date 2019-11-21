#include<bits/stdc++.h>
using namespace std;

int main ( )
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%c",&c[i]);
	map[1][1]=c[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&u);
		map[u][i]=c[i];
	}
	for(int i=1;i<=n;i++)
	{
		work(i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
