#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long a=1,k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		a*=2;
	for(int i=n;i>=1;i--)
	{
		a=a/2;
		if(k<a)
			cout<<"0";
		else
		{
			cout<<"1";
			k=2*a-k-1;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
