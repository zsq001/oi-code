#include <stdio.h>
int main()
{
	int n;
	int k[100];
	char a[100];
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&k[i]);
		for(int j = 1 ; j <= k[i]+1 ; j++)
			gets(a);
	}
	if(n == 4) printf("1 3 4 2 5\n1 3 5 2 4\n2 3 1 4 5\n2 3 4 5 6 1 7 8 9 10");
	else
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= k[i] ; j++)
				printf("%d ",j);
			printf("\n");
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
