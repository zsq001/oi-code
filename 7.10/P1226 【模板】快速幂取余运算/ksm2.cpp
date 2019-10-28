#include<iostream>
using namespace std;
int ksm(int x,int y,int z)
{
	long long ans=1,base=x;
	while(y)
	{
		if(y&1)
		ans=ans*base;//%z;
		base=base*base;//%z;
		y>>=1;
	}
	return ans;
}
int main()
{
	int b,p,k;
	cin>>b>>p;//>>k;
	cout<<ksm(b,p,k); 
	//cout<<b<<"^"<<p<<" mod "<<k<<"="<<ksm(b,p,k)%k;
	return 0;
}
