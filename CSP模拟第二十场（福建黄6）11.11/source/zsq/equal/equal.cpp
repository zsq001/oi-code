#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int next,v;
}a[100000];
int head[100000],cnt=0,a1[100011],b[100011];
void add(int u,int v)
{
	a[++cnt].v=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int aa,bb,ans=0;
		cin>>aa>>bb;
		if(aa==bb)
			cout<<n-1;
		for(int j=head[aa],l=0;j;j=a[j].next)
		{
			a1[j]=++l;
		}
		for(int j=head[bb],l=0;j;j=a[j].next)
		{
			b[j]=++l;
		}
		for(int j=1;j<=n;j++)
		{
			if(a1[j]==b[j])
				ans++;
		}
		cout<<ans<<endl;
	}
}
