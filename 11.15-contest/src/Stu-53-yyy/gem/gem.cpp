#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar(); bool f=0;
	while(c<'0'||'9'<c){f|=(c=='-'); c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	x=f?-x:x;
}
typedef long long ll;
const int N=200055;

int n,m;
ll a[N];
bool no2=1,ys=1,lsr=1;
struct opt{
	int tp,l,r;
	ll x,y;
}s[N];

namespace pt0{
	void solve(){
		int tp,l,r; ll x,y;
		ll res,in,out;
		for(int i=1;i<=m;i++){
			read(tp); read(l); read(r);
			if(tp==1){
				res=0;
				while(a[l]>=a[l+1]&&l<r)++l;
				if(l==r){puts("0");continue;}
				while(l<r){
					in=a[l];
					while(a[l]<=a[l+1]&&l<r)++l;
					out=a[l];
					if(out-in>0)res+=out-in;
					while(a[l]>=a[l+1]&&l<r)++l;
				}
				printf("%lld\n",res);
			}
			else {
				read(x); read(y);
				a[l]=x;
				for(int i=l+1;i<=r;i++)a[i]=a[i-1]+y;
			}
		}
	}
}

namespace pt1{
	ll sub[N];
	void solve(){
		int p=n;
		while(p){
			while(a[p]<=a[p-1]&&p){
				sub[p-1]=sub[p];
				--p;
			}
			while(a[p]>=a[p-1]&&p){
				sub[p-1]=sub[p]+a[p]-a[p-1];
				--p;
			}
		}
		int l,r;
		for(int i=1;i<=m;i++){
			l=s[i].l; r=s[i].r;
			printf("%lld\n",sub[l]-sub[r]);
		}
	}
}
namespace pt2{
	ll sub[N];
	void solve(){
		int p=n;
		while(p){
			while(a[p]<=a[p-1]&&p){
				sub[p-1]=sub[p];
				--p;
			}
			while(a[p]>=a[p-1]&&p){
				sub[p-1]=sub[p]+a[p]-a[p-1];
				--p;
			}
		}
		int l,r;
		for(int i=1;i<=m;i++){
			l=s[i].l; r=s[i].r;
			printf("%lld\n",sub[l]-sub[r]);
		}
	}
}

int main(){
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	if(n*m<=50000000){pt0::solve();return 0;}
	int tp,x,y; ll l,r;
	for(int i=1;i<=m;i++){
		read(tp); read(l); read(r);
		if(tp==2)read(x),read(y);
		no2&=(tp==1); ys&=(y==0); lsr&=(l==r);
		s[i]=(opt){tp,l,r,x,y};
	}
	if(no2){pt1::solve();return 0;}
	if(ys|lsr){pt2::solve();return 0;}
	return 0;
}
