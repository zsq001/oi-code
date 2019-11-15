#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#define mod 100000007
int cnt = 0;
int vis[1001][1001];
inline void dfs(int x,int y,int dep,int n)
{
	if(dep == n)
	{
		cnt ++;
		return;
	}
	if(!vis[x][y])dfs(x+1,y,dep+1,n);
	if(!vis[x][y])dfs(x,y+1,dep+1,n);
	if(!vis[x][y])dfs(x-1,y,dep+1,n);
}
using namespace std;
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n;
	cin>>n;
	dfs(0,0,0,n);
	cout<<(cnt%mod+(n-1)%mod)<<endl;
}
