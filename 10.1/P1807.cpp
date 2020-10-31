#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
const int mmm=100001;
const int inf=2147483647;
using namespace std;
struct node{
	int dis,v,next;
}a[mmm];
queue<int> q;
int ru[mmm],n,m,ts[mmm],cnt=0,head[mmm];
void add(int u,int v,int lo)
{
	a[++cnt].next=head[u];
	a[cnt].v=v;
	a[cnt].dis=lo;
	head[u]=cnt;
}
void topsort()
{
	while(!q.empty())
	{
		int w=q.front();
		q.pop();
		for(int i=head[w];i;i=a[i].next)
		{
			ru[a[i].v]--;
			ts[a[i].v]=max(ts[a[i].v],ts[w]+a[i].dis);
			if(ru[a[i].v]==0)
			{
				q.push(a[i].v);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,v;
		cin>>a>>b>>v;
		add(a,b,v);
		ru[b]++;
	}
	memset(ts,-inf,sizeof(ts));
	ts[1]=0;
	for(int i=1;i<=n;i++)
	{
		if(ru[i]==0)
			q.push(i);
		if(i!=1)
			ts[i]=-mmm;
	}
	topsort();
	if(ts[n]<0)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ts[n]<<endl;
	return 0;
}
