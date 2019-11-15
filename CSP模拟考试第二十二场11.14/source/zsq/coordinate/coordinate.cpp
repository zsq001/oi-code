#include<iostream>
#include<cstdio>
using namespace std;
typedef int int_;
#define int long long
const int MOD=1e9+7;
int_ main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n,a1=1,a2=1,a3;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a3=(a2*2+a1)%MOD;
		a1=a2%MOD;
		a2=a3%MOD;
	}
	cout<<a3<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
