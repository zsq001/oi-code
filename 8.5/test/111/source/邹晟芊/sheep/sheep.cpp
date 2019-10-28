#include<iostream>
#include<cstdio>
#define mmm 200010
using namespace std;
typedef int int_;
#define int long long 
int a[mmm];
int_ main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,ans=0,z;
		cin>>x;
		if(x==1)
		{
			cin>>y;
			while(y<n)
			{
				y+=a[y];
				ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(x==2)
		{
			cin>>y>>z;
			a[y]=z;
		}
	}
	return 0;
}
/*4
1 2 1 1
2
2 1 1
1 1*/

