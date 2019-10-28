#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b) x=1,y=0;
	else{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	ll x,y,m,n,l;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if(x==y){
		puts("0");
		return 0;
	}
	ll a=n-m,b=l,c=x-y;
	if(a<0){
		a=-a;
		c=-c;
	}
	//printf("a=%lld b=%lld c=%lld\n",a,b,c);
	ll d=gcd(a,b);
	if(c%d!=0){
		puts("Impossible");
		return 0;
	}
	ll k=c/d;
	a/=k,b/=k;
	exgcd(a,b,x,y);
	x*=k,y*=k;
	//printf("x=%lld y=%lld\n",x,y);
	printf("%lld",(x%l+l)%l);
	return 0;
}
