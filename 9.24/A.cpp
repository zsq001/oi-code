#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10];
int main()
{
	int sum=0;
	for(int i=1;i<=4;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%2==1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sort(a+1,a+5);
	if(a[1]+a[4]==a[2]+a[3])
		cout<<"YES"<<endl;
	else if(a[1]+a[2]+a[3]==a[4])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
