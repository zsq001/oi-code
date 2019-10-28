#include<iostream>
using namespace std;
#define mmm 301
int s[mmm][mmm],en[mmm];
int mmmm=-1;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>en[i];
		en[i+n]=en[i];
	}
	for(int i=2;i<2*n;i++)
	{
		for(int j=i-1;i-j<n&&j>=1;j--)
			{
				for(int k=j;k<i;k++)
				s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+en[j]*en[k+1]*en[i+1]);
				mmmm=max(s[j][i],mmmm);
			}
	}
	 cout<<mmmm;
	 return 0;
 } 
