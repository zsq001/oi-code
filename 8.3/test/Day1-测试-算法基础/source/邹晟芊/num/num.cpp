#include<iostream>
#include<queue>
typedef int int_;
#define int long long
using namespace std;
int a[20000*10000];
priority_queue<int> q;
int_ main()
{
	int n,m,k;
	int cnt=0;
	cin>>n>>m>>k;
	cnt=min(n,min(m,k));
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			a[i*j]++;
		}
	}
	cnt=0;
	while(k--)
	{
		if(a[cnt]==0)
		cnt++;
		a[cnt]--;
	}
	cout<<cnt;
	return 0; 
}
