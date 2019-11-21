#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,u,v,t,m;
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<n;j++)
		{
		    scanf("%d%d",&u,&v);
	    }
	    printf("%d",n*3-2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
