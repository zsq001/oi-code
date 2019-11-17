#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,treemin[10000010],treemax[10000010],a[1000010];
void build_tree(int x,int l,int r){
	if(l==r)  {
		treemin[x]=a[l];
		treemax[x]=a[l];
		return ;
	}	
	int mid=(l+r)>>1;
	build_tree(x<<1,l,mid);
	build_tree((x<<1)+1,mid+1,r);
	treemin[x]=min(treemin[x<<1],treemin[(x<<1)+1]);
	treemax[x]=max(treemax[x<<1],treemax[(x<<1)+1]);
}
void query(int t,int x,int y,int l,int r){
	int maxx=0,minn=0x7fffffff;
	if(x>=l&&y<=r){
		minn=min(minn,treemin[t]);
		maxx=max(maxx,treemax[t]);
		return ;
	}
	int mid=(x+y)>>1;
	query(t<<1,x,mid,l,r);
	query((t<<1)+1,mid+1,y,l,r);
	printf("%d\n",maxx-minn);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build_tree(1,1,n);
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r;
			scanf("%d%d",&l,&r);
			query(1,1,n,l,r);
		}
		if(op==2){
			int a1,a2,a3,a4;
			scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		}
	}
	return 0;
}
