#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ls o<<1
#define rs o<<1|1
int tree[100000001];
void query(int o,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr){
		tree[o]=v;
		return ;
	}
	int mid=(l+r)>>1;
	tree[o]=-1;
	if(ql<=mid){
		query(ls,l,mid,ql,qr,v);
	}
	if(qr>mid)query(rs,mid+1,r,ql,qr,v);
}
void Print(int o,int l,int r){
	if(tree[o]==-1){
		int mid=(l+r)>>1;
		Print(ls,l,mid);
		Print(rs,mid+1,r);
	}
	else{
		int len=r-l+1;
		for(int i=1;i<=len;i++){
			printf("%d\n",tree[o]);
		}
	}
}
int main(){
	int n,m,p,q;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	p%=n;q%=n;
	int qwq=max(0,m-n)+1;
	int hl=n+1,hr;
	for(int i=qwq;i<=m;i++){
		int a=(i*p+q)%n+1,b=(i*q+p)%n+1;
		if(a>b)swap(a,b);
		query(1,1,n,a,b,i);
	}
	Print(1,1,n);
}
