#include<bits/stdc++.h>
int a[110],ans[1010];
int main()
{    
    freopen ("a.in","r",stdin);
    freopen ("a.out","w",stdout);
    int t,n,i,j,b=0,c=0;
	scanf("%d\n",&t);	
	for(int k=1;k<=t;k++)
	{
	scanf("%d\n",&n);
	for(int j=1;j<=n;j++)
	scanf("%d",&a[j]);	
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]%3;
		if(a[i]==2) b++;
		if(a[i]==1) c++;
		if(a[i]==0) ans[k]++;
	}
	if(b==c) ans[k]+=b;
	if(b>c) 
	{
	ans[k]+=c;
	if((b-c)%3==0) ans[k]+=(b-c)/2;	
	}
		
	if(b<c) 
	{
	ans[k]+=b;
	if((c-b)%3==0) ans[k]+=(c-b)/3;
	}
	
	
	}
	for(int i=1;i<=t;i++)
	printf("%d\n",ans[i]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
