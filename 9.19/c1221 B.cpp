#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[110];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
				if((i+j)%2==1)
				cout<<"W";
				else
				cout<<"B";
		}
		cout<<endl;
	}
	return 0;
 } 
