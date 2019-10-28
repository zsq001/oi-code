#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[70],l,next1[70];
int longg;int n,cnt=0,tot=0;
bool vis[70],ccn=false;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k,int la,int re)//现在    前一jie     剩下的
{
	if(re==0)
	{
		if(k==longg)//xianzai == yuangeshu
		{
			ccn=true;
			return ;
		}
		int i;
		for(i=1;i<=cnt;i++)
			if(!vis[i])
				break;
		vis[i]=1;
		dfs(k+1,i,l-a[i]);
		vis[i]=0;
		if(ccn)
			return ;
	}
	int le=la+1,r=cnt,mid;
	while(le<r)
	{
		mid=(le+r)/2;
		if(a[mid]<=re)
			r=mid;
		else 
			le=mid+1;
	}
	for(int i=le;i<=cnt;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(k,i,re-a[i]);
			vis[i]=0;
			if(ccn)
				return;
			if(re==a[i]||re==l)
				return ;
			i=next1[i];
			if(i==cnt)
				return ;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{		
		int x;
		cin>>x;
		if(x<=50)
		{
			a[++cnt]=x;
			tot+=x;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	next1[cnt]=cnt;
	for(int i=cnt-1;i>0;i--)
	{
		if(a[i]==a[i+1])
			next1[i]=next1[i+1];
		else
			next1[i]=i;
	}
	for(l=a[1];l<=tot/2;l++)
	{
		if(tot%l!=0)
			continue;
		longg=tot/l;
		ccn=false;
		vis[1]=1;
		dfs(1,1,l-a[1]);
		vis[1]=0;
		if(ccn)
		{
			cout<<l;
			return 0;
		}
	}
	cout<<tot;
	return 0;
}
