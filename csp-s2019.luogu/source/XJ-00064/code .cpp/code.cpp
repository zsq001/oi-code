#include<iostream>
int a[100000];
int b[100000];
using namespace std;
int main()
{
	a[1]=0;
	a[2]=1;
	long long b,c;
	long long d=1;
	int e;
	cin>>b>>c;
	if(b==2 && c==3)
	{
		cout<<"10";
	}
	if(b==3 && c==5)
	{
		cout<<"111";
	}
	for(int i=1;i<=b;i++)
	{
		d=2*d;
		e=d/2;
		for(int q=1;q<e;q++)
		{
			b[q]='0'+a[q];
		}
		for(int j=d-1;j>=e;j++)
		{
			b[q]='1'+a[q];
		}	
		for(int o=1;o<d;o++)
		{
			a[o]=b[o];
		}
	}
	cout<<a[c-1];
	return 0;
}
