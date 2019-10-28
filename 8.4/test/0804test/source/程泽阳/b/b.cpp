//#pragma GCC optimize(2) 
#include<cstdio>
#define ll long long
ll a[100010],tree[400010],lazy[400010];
void write(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void pushup(int rt){tree[rt]=tree[rt<<1]+tree[rt<<1|1];}
void build(int rt,int l,int r){
	if(l==r){
		tree[rt]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt,int l,int r)
{
	int mid=(l+r)/2;
	tree[rt<<1]=lazy[rt];
	lazy[rt<<1]=lazy[rt];
	tree[rt<<1|1]=lazy[rt];
	lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=0;
}
void update(int rt,int l,int r,int ql,int qr,int val)
{
	if(l>=ql && r<=qr){
		lazy[rt]=val;
		tree[rt]=val;
		return ;
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(ql<=mid)update(rt<<1,l,mid,ql,qr,val);
	if(qr>mid)update(rt<<1|1,mid+1,r,ql,qr,val);
	pushup(rt);
}
ll query(int rt,int l,int r,int ql,int qr)
{
	ll ans=0;
	if(l>=ql && r<=qr){
		return tree[rt];
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(ql<=mid)ans+=query(rt<<1,l,mid,ql,qr);
	if(qr>mid)ans+=query(rt<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main()
{
	ll n,m,i,p,q;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	if(n<100000)
	{
		for(i=1;i<=m;i++)
		{
			ll x,y;
			x=(i*p+q)%n+1;
			y=(i*q+p)%n+1;	
			for(ll j=x;j<=y;j++)
			{
				tree[j]=i;	
			}
		}
		for(i=1;i<=n;i++)
		{
			write(tree[i]);
			putchar('\n');
		}
	}
	else
	{
		build(1,1,n);
		for(i=1;i<=m;i++)
		{
			ll x,y;
			x=(i*p+q)%n+1;
			y=(i*q+p)%n+1;
			update(1,1,n,x,y,i);
		}
		for(i=1;i<=n;i++)
		{
			write(tree[i]);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
