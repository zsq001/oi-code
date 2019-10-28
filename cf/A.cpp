#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a;
	if(a%4==1)
	{
		cout<<"0"<<" "<<"A";
	}
	if(a%4==3)
	{
		cout<<"2"<<" "<<"A";
	}
	if(a%4==2)
	{
		cout<<"1"<<" "<<"B";
	}
	if(a%4==0)
	{
		cout<<"1"<<" "<<"A";
	}
	return 0;
}
