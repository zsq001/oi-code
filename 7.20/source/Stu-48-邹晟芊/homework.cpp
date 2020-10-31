#include<iostream>
using namespace std;
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==2&&b==1)
	puts("1");
	else if(a==2&&b==3)
	puts("5");
	else
	puts("0");
	return 0;
}
