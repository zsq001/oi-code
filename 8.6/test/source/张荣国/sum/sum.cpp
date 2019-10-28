#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ls (o<<1)
#define rs (o<<1|1)
#define pushup(x) t[x]+=t[x<<1]+t[x<<1|1];
#define maxn 300005
template <class T> bool read(T &x){
	bool t=0;x=0;char s=getchar();if(s==-1)return 0;
	while(s<'0'||s>'9') {if(s=='-')t=1;else if(s==-1)return 0;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int lazy[maxn],t[maxn],n,m;
const int mod=1e9+7;
struct Mat{
	int A[5][5];
	int x,y;
	void init(bool flag){
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++)
				A[i][j]=0;
		if(flag) for(int i=1;i<=x;i++) A[i][i]=1;
	}
	Mat(int x_,int y_){
		x=x_;y=y_;
		init(0);
	}
	Mat operator *(Mat b){
		Mat a=*this;
		Mat c(a.x,b.y);
		c.init(0);
		for(int i=1;i<=a.x;i++){
			for(int j=1;j<=b.y;j++){
				for(int k=1;k<=a.y;k++)
					c.A[i][j]+=a.A[i][k]*b.A[k][j];
					c.A[i][j]%=mod;
			}
		}
		return c;
	}
	Mat operator ^(int b){
		Mat a=*this;
		Mat ret(2,2);
		ret.init(1);
		while(b){
			if(b&1) ret=ret*a;
			a=a*a;
			b>>=1;
		}
		return ret;
	}
};
void pushdown(int o,int l,int r){
	if(!lazy[o]) return ;
	int mid=(l+r)>>1;
	t[ls]+=lazy[o]*(mid-l+1);
	t[rs]+=lazy[o]*(r-mid);
	lazy[ls]+=lazy[o];
	lazy[rs]+=lazy[o];
	lazy[o]=0;
}
void build(int o,int l,int r){
	if(l==r) {
		read(t[o]);
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(o);
}
void add(int o,int l,int r,int ql,int qr,int val){
	if(ql<=l&&qr>=r){
		t[o]+=val;
		lazy[o]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) add(ls,l,mid,ql,qr,val);
	if(qr>mid) add(rs,mid+1,r,ql,qr,val);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(l<=ql&&r>=qr) return t[o];
	int ret=0;
	int mid=(l+r)>>1;
	pushdown(o,ql,qr);
	if(ql<=mid) ret+=query(ls,l,mid,ql,qr);
	if(qr>mid) ret+=query(rs,mid+1,r,ql,qr);
	return ret;
}

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n),read(m);
	int opt,l,r,z;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		read(opt);
		if(opt==1){
			read(l),read(r),read(z);
			add(1,1,n,l,r,z);
		}
		else {
			read(l),read(r);
			int x=query(1,1,n,l,r);
			Mat ans(2,2),ori(2,1);
			ans.A[1][1]=ans.A[1][2]=ans.A[2][1]=1;
			ori.A[1][1]=ori.A[1][2]=1;
			ans=ans^(x-2);
			ans=ans*ori;
			printf("%lld\n",ans.A[1][1]);
		}
	}
	return 0;
}
