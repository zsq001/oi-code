#include<iostream>
#include<cmath>

using namespace std;
int a[30001];
/*void pushup(int o)
{
	tree[o]=tree[o>>1]+tree[o>>1|1]; 
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		cin>>tree[o];
		return ;
	}
	int mid=(l+r)/2;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void pushdown(int o,int l,int r)
{
	if(!lazy[o])
	return ;
	int mid=(l+r)/2;
	tree[o<<1]+=lazy[o]*(mid-l+1);
	tree[o<<1|1]+=(r-mid)*lazy[o];
	lazy[o<<1]+=lazy[o];
	lazy[o<<1|1]+=lazy[o];
	lazy[o]=0;
}
void query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		
	}
}
void update(int o,int l,int r,int ql,int qr)
{
	if(ql>=l&&r<=qr)
	{
		an
	}
}*/
int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int op;
		cin>>op;
		if(op==0)
		{
			int q,w;
			cin>>q>>w;
			if(q==w)
			a[q]=floor(sqrt(a[q]));
			else
			{
				for(int j=q;j<=w;j++)
				a[j]=floor(sqrt(a[j]));
			}
		}
		else
		{
			int q,w;
			cin>>q>>w;
			if(q==w)
			cout<<a[q]<<endl;
			else
			{
				int ans=0;
				for(int j=q;j<=w;j++)
				ans+=a[j];
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
