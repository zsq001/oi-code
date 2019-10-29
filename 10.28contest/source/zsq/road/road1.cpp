#include<iostream>
#include<cstdio>
typedef int int_;
#define int long long
using namespace std;
int a[101000];
int_ main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])
			cnt+=a[i]-a[i-1];
	cout<<a[1]+cnt<<endl;
	return 0;
}
