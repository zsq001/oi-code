#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define mmm 100000
vector<int> tree[mmm];
int num[mmm],len[mmm],lef[mmm],f[mmm];
int mmax(int &a,int b)
{
	return a=a>b?a:b;
}
bool cmp(int &x,int &y)
{
	if(f[x]==f[y])
		return x<y;
	else
		return f[x]>f[y];
}
void dfs(int u,int v=-1)
{
	len[u]=1,lef[u]=u;
	for(int i=0;i<tree[u].size();i++)
	{
		int vv=tree[u][i];
		if(vv==v)
			continue;
		dfs(vv,u);
		if(len[u]<len[vv]+1||(len[u]==len[vv]+1&&lef[u]>lef[vv]))
			len[u]=len[vv]+1,lef[u]=lef[vv];
	}
	mmax(f[lef[u]],len[u]);
}
int main()
{
	int n,k;
	cin>>n>>k;
	k++;
	for(int i=2;i<=n;i++)
	{
		int t;
		cin>>t;
		t++;
		tree[i].push_back(t);
		tree[t].push_back(i);
	}
	dfs(k);
	for(int i=1;i<=n;i++)
		num[i]=i;
	sort(num+1,num+1+n,cmp);
	cout<<k-1<<endl;
	for(int i=1;i<=n;i++)
	{
		if(f[num[i]])
			cout<<num[i]-1<<endl;
	}
	return 0;
}
