#include<iostream>//±¨¡„‘§∂®
#include<cstdio>
#define mmm 200010
typedef int int_;
#define int long long 
using namespace std;
struct node{
	int num,aaa;
};
double a[mmm];
int_ main()
{
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	node ans;
	int n,m,lll=-1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		ans.aaa=0;
		ans.num=0;
		cin>>x>>y;
		a[x]=y/x*1.0000000;
		lll=max(lll,x);
		for(int j=1;j<=lll;j++)
		{
			if(a[j]>ans.aaa)
			{
				ans.aaa=a[j];
				ans.num++;
			}
		}
		cout<<ans.num<<endl;
	}
	return 0;
}
