#include<iostream>
#include<cstdio>
using namespace std;
#define mmm 500000
typedef int int_;
#define int long long
int a[mmm],d[mmm],b[mmm];
void build(int l,int r,int p)
{
	if(l==r)
	{
		d[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	d[p]=d[p*2]+d[p*2+1];
}
int getsum(int l,int r,int s,int t,int p)// ask[l,r]   nowinc[s,t] nownumber p
{
	if(l<=s&&t<=r)
		return d[p];
	int mid=(s+t)>>1,sum=0;
	if(b[p])
	{
		d[p<<1]+=b[p]*(mid-s+1);
		d[p*2+1]+=b[p]*(t-mid);
		b[p*2]+=b[p];
		b[p*2+1]+=b[p];
	}
	b[p]=0;
	if(l<=mid)
		sum+=getsum(l,r,s,mid,p*2);
	if(r>mid)
		sum+=getsum(l,r,mid+1,t,p*2+1);
	return sum;
}
void update(int l,int r,int c,int s,int t,int p)//c change
{
	if(l<=s&&t<=r)
	{
		d[p]+=(t-s+1)*c;
		b[p]+=c;
		return ;
	}
	int mid=(s+t)>>1;
	if(b[p])
	{
		d[p*2]+=b[p]*(mid-s+1);
		d[p*2+1]+=b[p]*(t-mid);
		b[p*2]+=b[p];
		b[p*2+1]+=b[p];
		b[p]=0;
	}
	if(l<=mid)
		update(l,r,c,s,mid,p*2);
	if(r>mid)
		update(l,r,c,mid+1,t,p*2+1);
	d[p]=d[p<<1]+d[p*2+1];
	
}
int_ main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int x,y,k,qwq;
		cin>>qwq>>x>>y;
		if(qwq==1)
		{
			cin>>k;
			update(x,y,k,1,n,1);
		}
		else
		{
			cout<<getsum(x,y,1,n,1)<<endl;
		}
	}
	return 0;
}
