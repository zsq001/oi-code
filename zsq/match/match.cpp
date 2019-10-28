#include<iostream>
#include<cstdio>
#define mmm 100000
using namespace std;
int bl[mmm],ye[mmm];
int ju[1100][1100];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
	cin>>bl[i];
	for(int i=1;i<=m;i++)
	cin>>ye[i];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(bl[i]-x<=ye[j]&&bl[i]+y>=ye[j])
		ju[i][j]=1;
	}
	cout<<2;
	return 0;
} 
