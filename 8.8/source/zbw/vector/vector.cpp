#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll a,b,x,y;
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		if(a<0) a=-a;
		if(b<0) b=-b;
		if((a==0&&b==0)&&(x!=0||y!=0)) puts("N");
		else if((x==0||y==0)&&a!=0&&b!=0) puts("N");
		else if(gcd(a,b)<=gcd(x,y)) puts("Y");
		else puts("N");
	}
	return 0;
}
