#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const int O = 1;
int tree[100010],lazy[100010];

void pushup(int o)
{
	tree[o] = tree[o<<1] + tree[o<<1|1];
}

//void pushdown(int o,int l,int r)
//{
//	if(lazy[o] == O) return;
//	int mid = (l+r)>>1;
//	
//	lazy[o<<1] += lazy[o];
//	lazy[o<<1|1] += lazy[o];
//	
//	tree[o<<1] += lazy[o];
//	tree[o<<1|1] += lazy[o];
//	
//	lazy[o] = O;
//}

void build(int o,int l,int r)
{
	lazy[o] = O;
	if(l == r)
	{
		scanf("%d",&tree[o]);
		return;
	}
	int mid = (l + r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

void update(int o,int l,int r,int ql,int qr)
{
	if(l == r)
	{
//		lazy[o] = sqrt(lazy[o]);
		tree[o] = sqrt(tree[o]);
		return;
	}
//	pushdown(o,l,r);
	int mid = (l+r)>>1;
	if(ql <= mid) update(o<<1,l,mid,ql,qr);
	if(qr > mid) update(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}

ll query(int o,int l,int r,int ql,int qr)
{
	if(ql <= l && qr >= r)
	{
		return tree[o];
	}
//	pushdown(o,l,r);
	int mid = (l+r)/2;
	ll ret = 0;
	if(ql <= mid) ret += query(o<<1,l,mid,ql,qr);
	if(qr > mid) ret += query(o<<1|1,mid+1,r,ql,qr);
	return ret;
}

int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int n;
	scanf("%d",&n);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++)
	{
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		if(k == 0)
			update(1,1,n,a,b);
		else
			printf("%lld\n",query(1,1,n,a,b));
	}
	return 0;
}
