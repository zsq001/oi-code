#include<stdio.h>
#include<algorithm>
#include<string.h>
typedef int int_;
#define int long long
using namespace std;
int ret;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int ex_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ret=ex_gcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
int main(){
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	int x,y,m,n,l,tmp,ans;
	read(x),read(y),read(m),read(n),read(l);
	int a=m-n,b=y-x;
	if(a<0) {
		a=-a;
		b=-b;
	}
	int gcd=ex_gcd(a,l,ans,tmp);
	if(b%gcd!=0) {
		printf("Impossible");
		return 0;
	}
	printf("%lld",((ans*(b/gcd)+(l/gcd))%(l/gcd))%(l/gcd));
	return 0;
}
