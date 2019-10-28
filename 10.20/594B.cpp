#include<iostream>
#include<cstdio>
#include<algorithm>
#define mmm 100100
int a[mmm];
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
			x+=a[i];
		else 
			y+=a[i];
	}
}	
