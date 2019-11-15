#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int i,n;
	scanf("%d",&n);
	long long a=3,b=1,c;
	for(i=2;i<=n;i++)
	{
		c=a;
		a=b*3+(a-b)*2;
		b=c;
	}
	a=a%1000000007;
	printf("%d",a);
	return 0;
}
