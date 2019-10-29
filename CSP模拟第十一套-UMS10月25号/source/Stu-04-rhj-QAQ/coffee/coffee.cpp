#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=100005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,h,b,e,minn[N<<2],pos[N<<2],cnt[N],tmin,ans;
void pushup(int rt)
{
	if(minn[rt<<1]==minn[rt<<1|1]) minn[rt]=minn[rt<<1],pos[rt]=max(pos[rt<<1],pos[rt<<1|1]);
	else if(minn[rt<<1]>minn[rt<<1|1]) minn[rt]=minn[rt<<1|1],pos[rt]=pos[rt<<1|1];
	else minn[rt]=minn[rt<<1],pos[rt]=pos[rt<<1];
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		read(minn[rt]),pos[rt]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		if(minn[rt]<tmin) tmin=minn[rt],ans=pos[rt];
		else if(minn[rt]==tmin) ans=max(ans,pos[rt]);
		return minn[rt];
	}
	int mid=(l+r)>>1,pmin=1<<30;
	if(L<=mid) pmin=min(pmin,query(rt<<1,l,mid,L,R));
	if(R>mid) pmin=min(pmin,query(rt<<1|1,mid+1,r,L,R));
	return pmin;
}
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		read(h),read(b),read(e);
		memset(minn,0x3f,sizeof(minn));
		memset(pos,0,sizeof(pos));
		memset(cnt,0,sizeof(cnt));
		build(1,1,n);
		for(int i=1;i<=n;++i)
		{
			tmin=1<<30,ans=0;
			query(1,1,n,max(1,i-h+1),i);
			cnt[ans]++;
		}
		for(int i=b;i<=e;++i) printf("%d ",cnt[i]);
		printf("\n");
	}
	return 0;
}
