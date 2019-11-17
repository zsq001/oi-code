#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,last,lastr;
ll lef[N<<2],rig[N<<2],maxn[N<<2],del[N<<2];
void pushup(int rt)
{
	lef[rt]=lef[rt<<1],rig[rt]=rig[rt<<1|1];
	maxn[rt]=maxn[rt<<1]+maxn[rt<<1|1]+max((long long)0,lef[rt<<1|1]-rig[rt<<1]);
}
void pushdown(int rt,int l,int r)
{
	if(del[rt])
	{
		int mid=(l+r)>>1;
		lef[rt<<1]=lef[rt],lef[rt<<1|1]=lef[rt]+(mid+1-l)*del[rt];
		rig[rt<<1]=lef[rt]+(mid-l)*del[rt],rig[rt<<1|1]=rig[rt];
		del[rt<<1]=del[rt],del[rt<<1]=del[rt];
		del[rt]=0;
	}
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		read(lef[rt]),rig[rt]=lef[rt],maxn[rt]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int L,int R,int x,int y)
{
	if(L<=l&&r<=R)
	{
		del[rt]=y;
		lef[rt]=x+(l-L)*y,rig[rt]=x+(r-L)*y;
		maxn[rt]=(r-l)*y;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(rt<<1,l,mid,L,R,x,y);
	if(R>mid) update(rt<<1|1,mid+1,r,L,R,x,y);
	pushup(rt);
}
ll query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return maxn[rt]+(l-lastr==1?max((long long)0,lef[rt]-rig[last]):0);
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	ll ret=0;
	if(L<=mid) ret+=query(rt<<1,l,mid,L,R),lastr=mid,last=rt<<1;
	if(R>mid) ret+=query(rt<<1|1,mid+1,r,L,R),lastr=r,last=rt<<1|1;
//	if(L<=mid&&R>mid) ret+=max((long long)0,lef[rt<<1|1]-rig[rt<<1]);
	return ret;
}
int main()
{
	read(n),read(m);
	build(1,1,n);
	while(m--)
	{
		int opt,l,r,x,y;
		read(opt),read(l),read(r);
		if(opt==1)
		{
			last=0,lastr=-1;
			printf("%lld\n",query(1,1,n,l,r));
		}
		else
		{
			read(x),read(y);
			update(1,1,n,l,r,x,y);
		}
	}
	return 0;
}
