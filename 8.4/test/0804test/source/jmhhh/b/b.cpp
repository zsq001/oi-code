#include<cstdio>
#include<algorithm>
using namespace std;



struct node{
	int color,time;
};
int lazy[4000050];

int tree[4000050];
int n,m,p,q;

void pushdown(int o){
	if(lazy[o]==0) return;
	else{
		lazy[o<<1]=lazy[o];
    	lazy[o<<1|1]=lazy[o];
    	lazy[o]=0;    
//    	printf("%d %d %d %d\n",lazy[2],lazy[5],lazy[6],lazy[7]);
	}
}

void add(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l && r<=qr){
		lazy[o]=x;
	}
	else{
		pushdown(o);
		int mid=(r+l)>>1;
		if(ql<=mid) add(o<<1,l,mid,ql,min(mid,qr),x);
		if(qr>mid) add(o<<1|1,mid+1,r,max(ql,mid+1),qr,x);
//		printf("%d %d %d %d\n",lazy[2],lazy[5],lazy[6],lazy[7]);
	}
	
}

void query(int o,int l,int r){
	if(r<=l) printf("%d\n",lazy[o]);
	else{
		pushdown(o);
		int mid=(r+l)>>1;
		query(o<<1,l,mid);
		query(o<<1|1,mid+1,r);
		return ;
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&p,&q);
	for(int i=1;i<=m;i++){
		int r=(i*p+q)%n+1;
		int l=(i*q+p)%n+1;
		if(r<l) swap(r,l);
//		printf("%d %d\n",r,l);
		add(1,1,n,l,r,i);
	}
	query(1,1,n);
	return 0;
}
