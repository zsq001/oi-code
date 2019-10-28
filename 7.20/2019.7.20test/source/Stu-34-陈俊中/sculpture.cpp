#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

long long  n,a[100010],m,tree[800010];

void pushup(int o)
{
	tree[o]=tree[o<<1]+tree[o<<1|1];
}

void build(int o,int l,int r)
{
	if(l==r)
	{
		scanf("%d",&tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

void update(int o,int l,int r,int ql,int qr)
{
	if(ql<l&&qr>r)
	{
		if(tree[o]==r-l+1);
		return ;
	}
	if(l==r)
	{
		tree[o]=(long long)sqrt(tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql>=mid) update(o<<1,l,mid,ql,qr);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}

long long  query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r) return tree[o];
	long long  ret=0;
	int mid=(l+r)>>1;
	if(ql<=mid) ret+=query(o<<1,l,mid,ql,qr);
	if(qr>mid) ret+=query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}

int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int op,l,r;
	scanf("%lld",&n);
	build(1,1,n);
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) printf("%lld\n",query(1,1,n,l,r));
		else update(1,1,n,l,r);
	}
	return 0;
}
