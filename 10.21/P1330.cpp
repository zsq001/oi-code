#include<iostream>
#include<cstdio>
#define mmm 100100
using namespace std;
struct node{
	int v,next;
}e[mmm];
bool lol=true;
int ans=0,cnt=0,head[mmm],col[mmm],use[mmm],tot[mmm];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool dfs(int now,int clo)
{
	if(use[now])
	{
		if(col[now]==clo)
			return true;
		//else 
			return false;
	}
	use[now]=1;
//	col[now]=clo;
	tot[col[now]= clo]++;
	lol=true;
	for(int i=head[now];i!=0&&lol;i=e[i].next)
	{
		lol=lol and dfs(e[i].v,1-clo);
	}
	return lol;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i])
			continue;
		tot[1]=tot[0]=0;
		if(!dfs(i,0))
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		ans+=min(tot[0],tot[1]);
	}
	cout<<ans<<endl;
	return 0;
}
