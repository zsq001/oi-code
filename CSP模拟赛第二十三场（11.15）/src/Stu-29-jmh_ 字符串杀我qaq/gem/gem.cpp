#include<cstdio>
#include<algorithm>
using namespace std;


int n,m,tot=1;
int a[800005],b[800005];
int tree[800005],lazy[800005];


void pushup(int o){
	tree[o]=max(tree[o<<1],tree[o<<1|1]);
}


void build(int o,int l,int r){
	if(l==r){
		tree[o]=b[++tot];
		return ;
	}
	int mid=(r+l)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}


int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i-1]=b[i]-b[i-1];
	}
	build(1,1,n-1);
	for(int i=1;i<=m;i++){
		int opt,tl,rt,x,y;
		scanf("%d",)
	}
}
