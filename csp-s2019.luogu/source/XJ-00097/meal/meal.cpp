#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m,c;
int a[102],b[102][2002];
long long ans;
int main()
{
freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		c=0;
		cin>>b[j][++c];
	}
	int d=1,e;
	for(int i=1;i<=n;i++)
	a[i]=i;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(b[i][j])
		{
			while(b[i][j])
			{
				d+=b[i][j];
				b[i][j]--;
			}
			ans+=d;
		}
	}
	cout<<(ans-n)*pow(10,n-2);
	return 0;
}	
