#include<bits/stdc++.h>
using namespace std;
long long k,n,m,i,d,s=0;


int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	m=1;
	for(i=1;i<=n;++i)
	 m=m*2;
	int a[n];
	char b[n];
	d=m;
	for(i=0;i<n;++i)
	
	
	{
	m=m/2;
	if(k<m)
	a[i]=0;
	else
	a[i]=1,k=2*m-k-1;
	
}
m=1;
for(i=0;i<n;++i)
{
 printf("%d",a[i]);

}
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}
