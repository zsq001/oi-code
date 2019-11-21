#include<bits/stdc++.h>
using namespace std;
int a[1001],p[1001],l[1001],r[1001],b[1001];
int type[2]={0,1};
int x,y,z,b1,b2,m,n;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type[2]>>a[1001];
	if(type[2]=0)
	{

		if(n<10)
		{
			cout<<a^2+n^2;
		}
		if(n<=50,a<10^3)
		{
			cout<<"0";
		}
	}
	else
	{
		a=(b[1001]mod(r[1001]-l[1001]+1)+l[1001]);
		if(n>4*10^7)
		{
			cout<<"sorry";
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
