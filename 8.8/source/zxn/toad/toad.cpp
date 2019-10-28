#include<cstdio>
typedef int int_;
#define int long long
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void exgcd(int a,int b,int &x,int &y){
	if(!b)x=1,y=0;
	else{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int_ main(){
	int x,y,n,m,l;
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	int a=n-m,b=l,c=x-y;
	if(a<0){
		a=-a,c=-c;
	}
	int d=gcd(a,b);
	if(c%d){
		puts("Impossible");
		return 0;
	}
	a/=d,b/=d,c/=d;
	exgcd(a,b,x,y);
	x=x*c%b;
	x=((x%b)+b)%b;
	printf("%lld",x);
}
