#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
				cout<<"No";
			return 0;
		}
		cout<<"Yes";
	}
	return 0;
} 
