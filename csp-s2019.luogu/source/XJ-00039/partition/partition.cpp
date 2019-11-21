#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100010]={0};
int main()
{
	int n,k,d=0;
	long long int ans=0;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
 	    scanf("%d",&a[i]);
    }
    for(int i=1;i<n-d;i++)
    {
    	if(a[i]>a[i+1])
    	{
    		if(a[i]>a[i+2]&&a[i+2]!=0)
    		{
			    a[i+1]+=a[i+2];
    		    for(int j=i+3;j<=n-d;j++)
    		    a[j-1]=a[j];
    		    a[n-d]=0;
    		    d++;
				
    	    }
    		else 
    		{
    		    a[i]+=a[i+1];
    		    for(int j=i+2;j<=n-d;j++)
    		    a[j-1]=a[j];
    		    a[n-d]=0;
    		    d++;
    	    }
    	    i--;
    	}
    }
    for(int i=1;i<=n-d;i++)
    if(a[i]>0) ans+=a[i]*a[i];
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
