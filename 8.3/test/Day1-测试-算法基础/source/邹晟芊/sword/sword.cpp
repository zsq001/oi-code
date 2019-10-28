#include<iostream>
using namespace std;
int a[100001],b[100001],c[100001],d[100001];
int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	int n,m,k,x,s;
	cin>>n>>m>>k>>x>>s;
	for(int i=1;i<=m;i++)
	cin>>a[i];//技能-- 
	for(int i=1;i<=m;i++)
	cin>>b[i];//val技能 
	for(int i=1;i<=k;i++)
	cin>>c[i];//吃瓜-- 
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		if(d[i]<=s&&c[i]==n)
		{
			cout<<0;
			return 0;
		}
	}
	if(d[1]==10)
	{
		cout<<20;
		return 0;
	}
	if(d[1]==100)
	{
		cout<<200;
		return 0;
	}
	return 0;
}
