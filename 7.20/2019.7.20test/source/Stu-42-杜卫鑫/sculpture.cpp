#include <stdio.h>
#include <math.h>
typedef int int_;
#define int long long
int tree[400005];
void pushup(int o){tree[o]=tree[o<<1]+tree[o<<1|1];}
void build(int o,int l,int r)
{
	if(l==r)
	{
		scanf("%lld",&tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr)
{
	if(l==r&&ql<=l&&qr>=r)
	{
		tree[o]=sqrt(tree[o]);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)update(o<<1,l,mid,ql,qr);
	if(qr>mid)update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)return tree[o];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=query(o<<1,l,mid,ql,qr);	
	if(qr>mid)res+=query(o<<1|1,mid+1,r,ql,qr);	
	return res;
}
int_ main()
{
	int n,m,x,y,op;
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	scanf("%lld",&n);
	build(1,1,n);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op)
		{
			printf("%lld\n",query(1,1,n,x,y));
		}
		else   update(1,1,n,x,y);
	}
	return 0;
}
