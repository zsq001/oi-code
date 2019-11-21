#include<bits/stdc++.h>
using namespace std;
int a[500001],ans=0,flag=0;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,m,type,max=0;
	cin>>n>>type;
	m=n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
	    if(a[n]<a[n-1])
	    {
    		a[n-1]+=a[n];a[n]=0;n--;
    	}
    	for(int j=1;j<=n;j++)
        {
    		for(int i=1;i<=n;i++)
    	    {
                if(a[i]>max) max=a[i];
        	}
        	if(a[n]!=max)
	        {
	        	a[n-1]+=a[n];a[n]=0;n--;
	        }
    	}
    	max=0;
    	n--;flag++;
	}
//	for(int i=1;i<=m;i++)
//	cout<<a[i]<<" ";
	for(int i=1;i<=m;i++)
	ans+=a[i]*a[i];
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
