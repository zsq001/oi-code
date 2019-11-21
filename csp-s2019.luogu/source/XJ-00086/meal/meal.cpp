 #include<bits/stdc++.h>
using namespace std;
long long a[50][5],p,ans;
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		for(long long int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}

	}
    for(long long int i=1;i<=n;i++)
    {
    	for(long long int j=1;j<=m;j++)
    	for(long long int k=i+1;k<=n;k++)
    	for(long long int b=1;b<=m;b++)
    	{
    		if(b==j) continue;
    		else
    		{
    			ans+=a[i][j]*a[k][b];
			}
		}
    		
		
	}
	for(long long int i=1;i<=n;i++)
    {
      for(long long int p=1;p<=n;p++)
      for(long long int q=1;q<=n;q++)
      {
      	if(i!=p&&p!=q&&q!=i) ans+=a[i][1]*a[p][2]*a[q][3];
	  }
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}          
