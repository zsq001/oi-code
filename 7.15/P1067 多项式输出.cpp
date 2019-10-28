#include<iostream>
using namespace std;
int xi[110];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++)
		cin>>xi[i];
	if(xi[1]==1)
	cout<<"x^"<<n;
	else if(xi[1]==-1)
	cout<<"-x^"<<n;
	else if(xi[1]!=0)
	cout<<xi[1]<<"x^"<<n;
	for(int i=2;i<=n;i++)
	{
		if(xi[i]!=0&&i!=n)
		{
			if(xi[i]==1)
			{
				cout<<"+x^"<<n+1-i;
			}
			else if(xi[i]==-1)
			{
				cout<<"-x^"<<n+1-i;
			}
			else if(xi[i]>0)
			cout<<"+"<<xi[i]<<"x^"<<(n+1-i);
			else
			cout<<xi[i]<<"x^"<<(n+1-i);
		}
		else if(xi[i]!=0)
		{
			if(xi[i]==1)
			{
				cout<<"+x";
			}
			else if(xi[i]==-1)
			{
				cout<<"-x";
			}
			else if(xi[i]>0)
			cout<<"+"<<xi[i]<<"x";
			else
			cout<<xi[i]<<"x";
		}
	}
	if(xi[n+1]>0)
	cout<<"+"<<xi[n+1];
	else if(xi[n+1]<0)
	cout<<xi[n+1];
	return 0;
}
