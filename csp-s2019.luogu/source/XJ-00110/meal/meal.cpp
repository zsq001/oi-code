#include<bits/stdc++.h>

using namespace std;
int a[102][501],c[501];	
int  m;
int ans=0,cai=0,i,j,p=0;
int n,mins=9999999,h;
void meal(int i,int j,int k)
{	   	 
    if(i==1&&j==(m+1)) 
    {
    	k-=1;
    	p++;

    }
    if(k>=2&&a[i][j]>0&&i<=n&&j<=m)
	{
		for(int h=1;h<=m;h++)
	        if(a[i][h]>0) c[h]--;
	   cai++;
	   if(cai==k)
	   {
	   	ans++;
	   	if(j<m)
	   	{
	   		for(int h=1;h<=m;h++)
	        if(a[i][h]>0) c[h]++;
			meal(i,j+1,k);
	   	}
		else if(i<n)
		   {
		   	c[j]++;
		   	meal(i+1,1,k);
		   }
	    else 
	   	 meal(1,j+1,k);
	   }
	    if(c[j]>0) meal(i+1,j,k);
	   else if(i<=n&&j<=m) meal(i+1,j+1,k);
	   meal(1,1+p,k);
	   meal(i+p,1,k);
	}
	    

}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);

	scanf("%d %d",&n,&m);
	for(int d=1;d<=n;d++)
	for(int f=1;f<=m;f++)
    	scanf("%d",&a[d][f]);
    
    for(int d=1;d<=n;d++)
	for(int f=1;f<=m;f++)
    	{
    		if(a[d][f]>0) 
			c[f]++;
    	}	
    for(int f=1;f<=m;f++)
    if(c[f]>1)
    c[f]/=2;	
    
    if(mins>n) mins=n;
	if(mins>(m*n/2)) mins=m*n/2;
	meal(1,1,mins);		
	printf("%d",ans);    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
