#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[50][5]={0},s[5]={0},h[50]={0};
int main()
{
	int sum;
	int n,m,d=1;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j]) 
		{
			s[j]++;
			h[i]++;
		}
	}
    sum=h[1]*h[2]-s[1]/2-s[2]/2-s[3]/2;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
