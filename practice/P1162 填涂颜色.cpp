#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int num,vis;
}a[32][32];
int n;
int x[]={0,-1,1};
int y[]={0,0,0,-1,1};
void dfs(int k,int l)
{
	if(k<0||k>n+1||l<0||l>n+1||a[k][l].vis==1||a[k][l].num==1)
	return ;
	a[k][l].vis=1;
	for(int i=1;i<=4;i++)
	dfs(k+x[i],l+y[i]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j].num;
		a[i][j].vis=0;
	}
	dfs(0,0);
	dfs(0,n);
	dfs(n,0);
	dfs(n,n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i][j].vis==0&&a[i][j].num!=1)
		a[i][j].num=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j].num<<" ";
		}
		cout<<endl;
	}
	return 0;
}
