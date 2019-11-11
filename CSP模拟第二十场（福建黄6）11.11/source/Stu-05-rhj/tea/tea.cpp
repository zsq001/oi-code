#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=10000005;
const int inf=1<<30;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int m,qwq,last=1,minn,tree[800005];
bool vis[100005];
queue<int>q;
void pushup(int rt){tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tree[rt]=l-1;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int x,int k)
{
	if(l==r)
	{
		tree[rt]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(rt<<1,l,mid,x,k);
	else update(rt<<1|1,mid+1,r,x,k);
	pushup(rt);
}
void solve1()
{
	while(m--)
	{
		int opt,x;
		read(opt);
		if(opt==1)
		{
			read(x);
			if(qwq) x^=last;
			vis[x]=1;
			if(minn==x)
				for(int i=minn;vis[i];++i) minn=i+1;
		}
		else if(opt==2)
		{
			read(x);
			if(qwq) x^=last;
			vis[x]=0;
			q.push(x);
			minn=min(minn,x);
		}
		else if(opt==3)
			while(q.empty()==0)
			{
				x=q.front();
				q.pop();
				if(vis[x]==0)
				{
					vis[x]=1;
					if(minn==x)
						for(int i=minn;vis[i];++i) minn=i+1;
					break;
				}
			}
		else printf("%d\n",last=minn);
	}
}
void solve2()
{
	build(1,1,100001);
	while(m--)
	{
		int opt,x;
		read(opt);
		if(opt==1)
		{
			read(x);
			if(qwq) x^=last;
			vis[x]=1;
			update(1,1,100001,x+1,inf);
		}
		else if(opt==2)
		{
			read(x);
			if(qwq) x^=last;
			vis[x]=0;
			q.push(x);
			update(1,1,100001,x+1,x);
		}
		else if(opt==3)
			while(q.empty()==0)
			{
				x=q.front();
				q.pop();
				if(vis[x]==0)
				{
					vis[x]=1;
					update(1,1,100001,x+1,inf);
					break;
				}
			}
		else printf("%d\n",tree[1]);
	}
}
int main()
{
	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	read(m),read(qwq);
	if(m<=2000) solve1();
	else if(m<=100000) solve2();
//	else solve3();???????
	return 0;
}
