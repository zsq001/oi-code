#include <cstdio>
#define LE(x) ((x)*2)
#define RT(x) ((x)*2+1)
#define MAXN 131072

typedef long long ll;

///////////////////////Segment Tree///////////////////////

ll flag[4*MAXN+5]={0},sum[4*MAXN+5]={0};

void pushdown(ll x,ll l,ll r)
{
	sum[x]+=(r-l+1)*flag[x];
	flag[LE(x)]+=flag[x];
	flag[RT(x)]+=flag[x];
	flag[x]=0;
}

ll l,r,k;

ll ins(ll x,ll cL,ll cR)
{
	ll mid=(cL+cR)/2,t;
	
	if(l<=cL && cR<=r) {flag[x]+=k;return (cR-cL+1)*k;}
	if(l>cR || r<cL) return 0;
	
	t=ins(LE(x),cL,mid)+ins(RT(x),mid+1,cR);
	
	sum[x]+=t;
	return t;
}

ll ask(ll x,ll cL,ll cR)
{
	ll mid=(cL+cR)/2;
	
	pushdown(x,cL,cR);
	
	if(l<=cL && cR<=r) return sum[x];
	if(l>cR || r<cL) return 0;
	
	return ask(LE(x),cL,mid)+ask(RT(x),mid+1,cR);
}

void add(ll _l,ll _r,ll _k)
{
	l=_l,r=_r,k=_k;
	ins(1,1,MAXN);
}

void get(ll _l,ll _r)
{
	l=_l,r=_r;
	printf("%lld\n",ask(1,1,MAXN));
}

///////////////////////Segment Tree///////////////////////

ll n,m;

void init()
{
	ll i,t;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		add(i,i,t);
	}
}

void play()
{
	ll i,opt,x,y,k;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&opt);
		if(opt==1)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			add(x,y,k);
		}
		else
		{
			scanf("%lld%lld",&x,&y);
			get(x,y);
		}
	}
}

int main(void)
{
	init();
	play();
	
	return 0;
}
