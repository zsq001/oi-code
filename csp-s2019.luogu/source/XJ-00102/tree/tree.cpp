#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r");
	freopen("tree.out","w");
	int t,n,a[100][100];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			scanf("%d",&n);
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		printf("%d",a[i][j]);	
		}
    }
	return 0;
	fclose(stdin);
	fclose(stdout);
}
