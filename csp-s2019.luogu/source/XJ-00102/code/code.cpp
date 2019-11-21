#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[100][100],t=0;
int main()
{
	freopen("code.in","r");
	freopen("code.out","w");
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		a[i][j]=(0,1);
		if(n==1) i=k;printf("%d",a[i][j]);
		for(j=1;j<n;j++)
		{
		    a[i-1][j]=t;
			if(a[i-1][j]<a[i-1][j+1]) a[i-1][j]=t;t=a[i-1][j+1];a[i-1][j+1]=a[i-1][j];
		    a[i][j]=t+a[i-1][j];
	    }
	}
	printf("%d",a[i][j]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
