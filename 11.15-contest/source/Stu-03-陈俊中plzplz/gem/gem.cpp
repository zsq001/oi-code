#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define maxn 200010
#define ls o<<1
#define rs o<<1|1
#define Mid (l+r)>>1
using namespace std;

int n,m,a[maxn];
ll tr1[maxn<<4],tr2[maxn<<4],d[maxn<<4];
const ll INF=0x7fffffff;

void pushup(int o)
{
	tr2[o]=tr1[o]=0;
	tr2[o]+=tr2[ls]>0?tr2[ls]:0;
	tr2[o]+=tr2[rs]>0?tr2[rs]:0;
	tr1[o]=tr1[ls]+tr1[rs];
}

void update(int o,int l,int r,int val)
{
	 if(val>0) tr2[o]=1ll*val*(r-l+1);
	 else tr2[o]=0;
	 tr1[o]=1ll*val*(r-l+1);
	 d[o]=val;
}

void pushdown(int o,int l,int r)
{
	if(d[o]!=-INF)
	{
		int mid=Mid;
		update(ls,l,mid,d[o]);
		update(rs,mid+1,r,d[o]);
		d[o]=-INF;
		pushup(o);
	}
}

void build(int o,int l,int r)
{
	if(l==r) 
	{
		tr1[o]=tr2[o]=a[l]-a[l-1];
		if(l==1) tr2[o]=0;
		return;
	}
	int mid=Mid;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(o);
	return ;
}

ll query1(int o,int l,int r,int ql,int qr)
{
	if(l>ql||r<qr) return 0;
	if(l==r) return tr1[o];
	if(ql<=l&&r<=qr) return tr1[o];
	int mid=Mid;
	if(d[o]!=-INF) pushdown(o,l,r);
	ll ret=0;
	ret=query1(ls,l,mid,ql,qr)+query1(rs,mid+1,r,ql,qr);
	pushup(o);
	return ret;
}

ll query2(int o,int l,int r,int ql,int qr)
{
	if(l>ql||r<qr) return 0;
	if(l==r) return tr2[o]>0?tr2[o]:0;
	if(ql<=l&&r<=qr) return tr2[o];
	int mid=Mid;
	if(d[o]!=-INF) pushdown(o,l,r);
	ll ret=0;
	ret=query2(ls,l,mid,ql,qr)+query2(rs,mid+1,r,ql,qr);
	pushup(o);
	return ret;
}

void change(int o,int l,int r,int ql,int qr,int val)
{
	if(l>ql||r<qr) return ;
	if(l==r)
	{
		if(l!=1) tr2[o]=tr1[o]=val;
		else tr1[0]=val;
		return ;
	}
	if(ql<=l&&r<=qr)
	{
		if(val>0) tr2[o]=1ll*val*(r-l+1);
		else tr2[o]=0;
		tr1[o]=1ll*val*(r-l+1);
		d[o]=val;
		return ;
	}
	int mid=Mid;
	pushdown(o,l,r);
	change(ls,l,mid,ql,qr,val);
	change(rs,mid+1,r,ql,qr,val);
	pushup(o);
}

int main()
{
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=4*n;++i) d[i]=-INF;
	while(m--)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			printf("%lld\n",query2(1,1,n,l+1,r));
		}
		else if(op==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ll l1=query1(1,1,n,1,l-1),r1=query1(1,1,n,1,r+1);
			change(1,1,n,l,l,x-l1);
			if(l+1<=r) change(1,1,n,l+1,r,y);
			ll r2=query1(1,1,n,1,r);
			change(1,1,n,r+1,r+1,r1-r2);
		}
	}
	return 0;
}
