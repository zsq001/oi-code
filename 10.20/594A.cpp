#include<iostream>
#include<cstdio>
#define mmm 1000000
typedef int int_;
#define int long long
using namespace std;
//int q[mmm],p[mmm];
int_ main()
{
	int t;
	cin>>t;
	for(int w=1;w<=t;w++)
	{
		int n,m,x,jp=0,op=0,jq=0,oq=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(x%2==0)
				op++;
			else
				jp++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x;
			if(x%2==0)
				oq++;
			else
				jq++;
		}
		cout<<jp*jq+op*oq<<endl;		
	}
	return 0;
}
