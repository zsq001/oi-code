#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 30020 
using namespace std;
int cnt,n,m,k; 
struct X{
	int num,ex;
}tree[maxn<<2];
void pushup(int o)
{
	tree[o].ex=tree[o<<1].ex+tree[o<<1|1].ex; 
}
void build(int o,int l,int r)
{
	if(l==r){
		tree[o].ex=1;
		tree[o].num=++cnt;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r); 
	pushup(o);
}
int update(int o,int l,int r,int x)
{
	if(l==r){
		tree[o].ex=0;
		return tree[o].num; 
	}
	int ret=0;
	int mid=(l+r)>>1;
	if(x<=tree[o<<1].ex) ret=update(o<<1,l,mid,x);
	else ret=update(o<<1|1,mid+1,r,x-tree[o<<1].ex); 
	pushup(o);
	return ret;
}
int main()
{
	cin>>n>>m;
	k=m;
	build(1,1,n);
	for(int i=n-1;i>=0;--i){
		cout<<update(1,1,n,k)<<" ";
		if(i) k=(k-2+m+i)%i+1;
	}
	return 0; 
}
