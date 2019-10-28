#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);	
	char a[100010][20];
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",a[1]);
	for(int i=0;i<m;i++){a[1][i]-='0';}
	for(int i=2;i<=n;i++)
	{
		scanf("%s",a[i]);
		for(int j=0;j<m;j++)
		{
			a[i][j]-='0';
			a[i][j]^=a[i-1][j];
		}
	}
	int cnt=0;
	if(n>=(2<<m))
	{
		printf("0\n");
		return 0;
	}
	for(int j=0;j<m;j++)
	{
		if(a[n][j]) cnt++;
	}
	printf("%d\n",cnt/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
