#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long 


int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
	}
	else{
		exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
}


int t,a,b,p,q;





int_ main()
{
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&a,&b,&p,&q);
		if(a<0) a=-a;
		if(b<0) b=-b;
		if(a==0 && b==0){
			if(p==0 && q==0) printf("Y\n");
			else printf("N\n");
			continue;
		}
		else if(a==0 || b==0){
			if(a==0) swap(a,b);
			if(p%a==0 && q%a==0) printf("Y\n");
			else printf("N\n");
			continue;
		}
		int d=gcd(a,b);
		if(p%d!=0 || q%d!=0){
			printf("N\n");
			continue;
		}
		int x,y;
		exgcd(a,b,x,y);
		int c=a+b;
		if((x-y)%2!=0 && c%2==0) printf("N\n");
		else printf("Y\n");
	}
	return 0;
}
