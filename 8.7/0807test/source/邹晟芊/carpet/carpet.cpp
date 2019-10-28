#include<iostream>
#include<cstdio>
using namespace std;
int a[2001][2001];
int main()
{
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=y1;j<=y2;j++)
		for(int k=x1;k<=x2;k++)
		a[k][j]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
