#include<bits/stdc++.h>
using namespace std;
int a[2^64-1];
int x=0,y=1,n,m,c;
int main()
{
		//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	cin>>n>>m;
	int c=pow(2,n);
	if(n==1&&m==2)
	{
	  cout<<1;return 0;}
	  for(int i=0;i<n;++i)a[0]=0;
	  for(int i=0;i<n;++i)cout<<a[0];
	  a[0]=a[0]; return 0;
	  for(int i=1;i<n;++i)a[1]=1;
	  for(int i=1;i<n;++i)
	  {cout<<a[0]<<a[1];}
      cout<<0;
      return 0;
	

}
