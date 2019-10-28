#include<iostream>
#include<algorithm>
using namespace std;
#define mmm 1000010
struct node {
	int l,r;
	int lazy,tag,sum;
}aaa[3*mmm]; 
void build(int i,int l,int r)
{
	aaa[i].l=l;
	aaa[i].r=r;
	aaa[i].lazy=0;
	aaa[i].tag=0;
	if(l==r)
	{
		aaa[i].sum=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	aaa[i].sum=aaa[i<<1].sum+aaa[i<<1|1].sum;
}
void update(int i,int l,int r,int v)
{
	if(aaa[i].l==l&&aaa[i].r==r)
	{
		aaa[i].lazy=1;
		aaa[i].tag=v;
		aaa[i].sum=(r-l+1)*v;
		return ;
	}
	int mid=(aaa[i].l+aaa[i].r)>>1;
	if(aaa[i].lazy==1)
	{
		aaa[i].lazy=0;
		update(i<<1,aaa[i].l,mid,aaa[i].tag);
		update(i<<1|1,mid+1,aaa[i].r,aaa[i].tag);
		aaa[i].tag=0;
	}
	if(r<=mid) update(i<<1,l,r,v);
	else if(l>mid) update(i<<1|1,l,r,v);
	else 
	{
		update(i<<1,l,mid,v);
		update(i<<1|1,mid+1,r,v);
	}
	aaa[i].sum=aaa[i<<1].sum+aaa[i<<1|1].sum;
}
int main()
{
	int x,y,z;
	int n,m,t;
	cin>>t;
	int iii=0;
	while(t--)
	{
		iii++;
		scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",iii,aaa[1].sum);
	}
	return 0;
} 
