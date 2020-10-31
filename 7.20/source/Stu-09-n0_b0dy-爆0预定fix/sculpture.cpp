#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void read(int &x)
{
	int f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
void llread(long long &x)
{
	int f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m;
long long sum[400005],maxn[400005];
void pushup(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		llread(sum[rt]),maxn[rt]=sum[rt];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int L,int R)
{
	if(l==r)
	{
		sum[rt]=(long long)sqrt(sum[rt]);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid&&maxn[rt<<1]>1) update(rt<<1,l,mid,L,R);
	if(R>mid&&maxn[rt<<1|1]>1) update(rt<<1|1,mid+1,r,L,R);
	pushup(rt);
}
long long query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return sum[rt];
	int mid=(l+r)>>1;
	long long ans=0;
	if(L<=mid) ans+=query(rt<<1,l,mid,L,R);
	if(R>mid) ans+=query(rt<<1|1,mid+1,r,L,R);
	return ans;
}
int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	read(n);
	build(1,1,n);
	read(m);
	while(m--)
	{
		int op,l,r;
		read(op),read(l),read(r);
		if(op) printf("%lld\n",query(1,1,n,l,r));
		else update(1,1,n,l,r);
	}
	return 0;
}
