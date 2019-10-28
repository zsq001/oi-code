#include<iostream>
#include<cstdio>
using namespace std;
int aw[10000];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int qwq=n;
		for(int i=1;i<=n;i++)
		{
			cin>>aw[i];
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(max(aw[i],aw[j])%min(aw[j],aw[i])==0)
				{
					qwq--;
				}
			}
		cout<<qwq<<endl;
	}
	return 0;
}
