#include<iostream>
#include<cstdio>
#define mmm 300
bool f[mmm][mmm];
using namespace std;
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		f[x][y]=1;
	}
	for(int k=1;k<=n;k++)
	for(int j=1;j<=n;j++)
	for(int i=1;i<=n;i++)
	f[i][j]=f[i][j]||f[i][k]&&f[k][j];
	for(int i=1;i<=n;i++)
	{
		int w=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			else	
			w=w&&(f[i][j]||f[j][i]);
		}
		ans+=w;
	}
	cout<<ans;
	return 0;
//	f[i][j]=f[i][j]f[i]&& 
}
