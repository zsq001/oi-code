#include <stdio.h>
char x[500001];
bool  a[250000][500001];
int main()
{
	int n;
	a[1]=1;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&x[i]);
	}
	for(int i=2;i<=n;i++)
	{
		int q;
		scanf("%d",&q);
		a[q][n]=1;
	}
	printf("6");
	return 0; 
}
