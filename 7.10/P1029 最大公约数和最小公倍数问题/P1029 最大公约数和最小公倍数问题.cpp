#include<iostream>
#include<cmath>
using namespace std;
int gcd(int x,int y)
{
	if(y==0)
	return x;
	return gcd(y,x%y);
}
int main()
{
	int x0,y0,ans;
	cin>>x0>>y0;
	for(int i=1;i<=sqrt(x0*y0);i++)
	if((x0*y0)%i==0&&gcd(i,(x0*y0)/i)==x0)
	ans++;
	cout<<2*ans;
	return 0;
}
