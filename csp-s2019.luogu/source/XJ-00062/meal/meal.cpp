#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int b[6];
int main()
{
	int a[35][35];
	int n,m,i,j,k,p,q,h,s=0;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	 for(i=2;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			  {
			  	if(a[j][k]>0)
			  	{
			  		b[k]++;
				    {
				     for(q=j+1;q<=n;q++)
					  for(p=1;p<=m;p++)
					   for(h=2;h<=i;h++) 
					    if(a[q][p]>0)
					    {
					    	b[p]++;
					    	if(b[p]<=i/2)s++;
						}
				 
			  		  }	 
				    b[k]=0;     
			    }
		}
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
