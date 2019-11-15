#include<iostream>
#include<cstdio>
#include<vector>
vector<int> aa[mmm];
using namespace std;
struct node{
	int v,next;
}a[mmm];
int cnt=0,head[mmm<<2],f[mmm][30];
void add(int u,int v)
{
	a[++cnt].v=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int now,int fa)
{
	f[now][0]=fa;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int f,t;
		cin>>f>>t;
//		aa[f].push_back(t);
//		aa[t].push_back(f);
		add(f,t);
		add(t,f);
	}
	dfs(1);

}
