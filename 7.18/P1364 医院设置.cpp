#include<iostream>
#define mmm 1000
#define mmmm 900101010
using namespace std;
struct node{
	int to,next;
}e[mmm*2];
int num,size[mmm],w[mmm],head[mmm],a,b;
long long ans=2147483647,f[mmm];
void add(int a,int b)
{
	e[++num].to=b;
	e[num].next=head[a];
	head[a]=num;
}
void dfs(int u,int fat,int dep)
{
	size[u]=w[u];
	for(int i=head[u];i;i=e[i].next)
	if(e[i].to!=fat)
	dfs(e[i].to,u,dep+1),size[u]+=size[e[i].to];
	f[1]+=w[u]*dep;
}
void dp(int u,int fat)
{
	for(int i=head[u];i;i=e[i].next)
	if(e[i].to!=fat)
	{
		f[e[i].to]=f[u]+size[1]-size[e[i].to]*2;
		dp(e[i].to,u);
	}
	ans=min(ans,f[u]);
}
int main()
{
	int n,i;
	cin>>n;
	ans*=ans;
	for(int i=1;i<=n;i++)
	//rep(i,1,n) 
	{
		cin>>w[i]>>a>>b;
		if(a) add(i,a),add(a,i);
		if(b) add(i,b),add(b,i);
	}
	dfs(1,0,0);
	dp(1,0);
	cout<<ans;
	return 0;
} 
