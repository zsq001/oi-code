#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
struct node{
	int l,r,mid,sum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define mid(x) tree[x].mid
	#define sum(x) tree[x].sum
}tree[MAXN<<2];
ll n,m;
template <class T> void read(T &x){
	int t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='0') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
void pushup(int o){ sum(o)=sum(o<<1)+sum(o<<1|1);}
void build(int o,int l,int r){
	l(o)=l,r(o)=r;
	mid(o)=(l+r)>>1;
	ll mid=mid(o);
	if(l==r){
		read(sum(o));
		return ;
	}
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(int o,int ql,int qr){
	int l=l(o),r=r(o);
	
	if(ql<=l&&r<=qr){
		if(sum(o)==r-l+1) return;
	}
	if(l==r){
		sum(o)=(ll)sqrt(sum(o));
		return ;
	}
	int mid=mid(o);
	if(ql<=mid) update(o<<1,ql,qr);
	if(qr>mid) update(o<<1|1,ql,qr);
	pushup(o);
}
ll query(int o,int ql,int qr){
	if(ql<=l(o)&&qr>=r(o)) return sum(o);
	ll mid=mid(o),ret=0;
	if(ql<=mid) ret+=query(o<<1,ql,qr);
	if(qr>=mid+1) ret+=query(o<<1|1,ql,qr);
	return ret;
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	read(n),read(m);
	build(1,1,n);
	int a,b,c;
	for(int i=1;i<=m;i++){
		read(a),read(b),read(c);
		if(a==1) printf("%d\n",query(1,b,c));
		else update(1,b,c);
	}
	return 0;
}
