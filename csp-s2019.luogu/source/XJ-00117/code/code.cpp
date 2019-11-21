#include<iostream>
#include<cstdio>
using namespace std;
typedef int int_;
#define int long long 
int pow(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)
	{
		ans*=a;
	}
	return ans;
}
int ccf(int x)
{
	return pow(2,x)/2;
}
int_ main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,k;
	cin>>n>>k;//3 5 
	k++;//6
	for(int i=n;i>0;i--)
	{
		if((k%pow(2,i+1)<=pow(2,i)/2) or (k%pow(2,i+1)>(pow(2,i)/2+pow(2,i))))
		{
//			cout<<i<<" ";
//			cout<<pow(2,i)<<" "; 
//			cout<<k<<" ";
//			cout<<ccf(i)<<" ";
			cout<<"0";
		}
		else 
			cout<<"1";
	}
	cout<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
