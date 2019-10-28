#include<iostream>
using namespace std;
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	x=1,y=0;
	else
	{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int main()
{
	int a,b;
	cin>>a>>b;
	int x,y;
	exgcd(a,b,x,y);
	cout<<((x%b)+b)%b;
	return 0;
}
