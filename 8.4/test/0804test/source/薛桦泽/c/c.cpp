#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,q,p;
struct Tree
{
	int s,t;
	int val;
}tree[4000012];
void build(int  x,int  y,int i)
{
	int mid=(x+y)/2;
	tree[i].s=x;
	tree[i].t=y;
	if(x==y) return;
	build(x,mid,i*2);
	build(mid+1,y,i*2+1);
}
void down_data(int w,int k)
{
	int mid=(tree[k].s+tree[k].t)/2;
	if(tree[k].s==tree[k].t) return;
	//printf("%d %d %d\n",tree[k].s,tree[k].t,tree[k].val);
	tree[k*2].val=w;
	down_data(w,k*2);
	tree[k*2+1].val=w;
	down_data(w,k*2+1);
	
}
void zone(int x,int y,int w,int k)
{
	//printf("%d %d(Çø¼ä)\n",x,y);
	if(tree[k].s>=x&&tree[k].t<=y)
	{
		tree[k].val=w;
		//printf("%d %d %d\n",tree[k].s,tree[k].t,tree[k].val);
		down_data(w,k);
		return ;
	}
	int mid=(tree[k].t+tree[k].s)/2;
	if(y>mid) zone(mid+1,y,w,k*2+1);
	if(x<=mid) zone(x,mid,w,k*2);
}
int find(int x,int k)
{
	if(tree[k].s==tree[k].t) return tree[k].val;
	int mid=(tree[k].s+tree[k].t)/2;
	if(x>mid) find(x,k*2+1);
	else find(x,k*2);
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int s=min((i*p+q),(i*q+p))%n+1;
		int t=max((i*p+q),(i*q+p))%n+1;
		zone(s,t,i,1);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",find(i,1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
