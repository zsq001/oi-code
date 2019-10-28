#include<iostream>
using namespace std;
const int mod=998224353;
int f[1010][1010]; 
int main()
{
	f[1][1]=1;
	cout<<1<<endl;
	for(int i=2;i<=1000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=(f[i-1][j]*2+f[i-1][j-1])%mod;
			if(i<=10&&j<=10)
			cout<<f[i][j]<<" ";
		}
		if(i<=10)
		cout<<endl;
	}
	return 0;
}
