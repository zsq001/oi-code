#include<iostream>//50points
#include<cstdio>
typedef int int_;
#define int long long 
int a[1000000];
using namespace std;
int_ main()
{
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	int n,j=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		i%=19260817;
		j++;
		a[j]=a[j-1]*2+i*2;
		a[j]=a[j]%19260817;
		if(j>100)
		{
			a[1]=a[j];
			j=2;
		}//1000000000
//		cout<<a[j]<<" ";
	}
	cout<<a[j-2]%19260817;
	return 0;
}
