#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001];
int n,m;
int parting(int k)
{
	for(k=1;k<=100;k++)
	{
		if(n!=n)
		{
			cout<<"0";
		}
		else
		{
			if(m>floor(k/2))
		    {
			    cout<<"0";
		    }
		    else
		    {
			    cout<<k;
		    }
		}
		   
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1001][1001];
	cin>>b[1001][1001];
	cout<<parting;
	fclose(stdin);fclose(stdout);
	return 0;
}

