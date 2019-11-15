#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int w,v,next;
}a[mmm];
void add(int u,int v,int w)
{
	a[++cnt].v=v;
	a[cnt].w=w;
	a[cnt].next=head[u];
	head[u]=cnt;
}
void bfs()
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int u,v,m;
		cin>>u>>v>>m;
		add(u,v,m);
	}
	for(int i=1;i<=q;i+=)
	{
	}
}
