#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
char a[100002][64],b[100002][64];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	long long int k;
	scanf("%d %lld",&n,&k);
	a[0][0]='0';
	a[1][0]='1';
	for(int i=1;i<n;i++)
	{
		int x=pow(2,i+1);
		for(int j=0;j<x/2;j++)
		{
			b[j][0]='0';
			strcat(b[j],a[j]);
		}
		for(int j=x/2;j<x;j++)
		{
			b[j][0]='1';
			for(int m=1;m<i+1;m++)
			  b[j][m]=a[x/2-(j-x/2)-1][m-1];
		}
		memset(a,0,sizeof(a));
		swap(a,b);
	}
	printf("%s",a[k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
