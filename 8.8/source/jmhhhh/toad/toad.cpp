#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

int x,y,n,m,l;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void exgcd(int a,int b,int &p,int &q){
	if(b==0){
		p=1,q=0;
	}
	else{
		exgcd(b,a%b,q,p);
		q-=(a/b)*p;
	}
}

int_ main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	scanf("%lld",&x);
	scanf("%lld",&y);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&l);
	
	int a=n-m,b=l,c=y-x;
	if(a<0){
		a=-a;
		c=-c;
	}
	int d=gcd(a,b);
	if(c%d!=0){
	    printf("Impossible");
	    return 0;
	}
	int p,q;
	exgcd(a,b,p,q);
	b/=d;
	p*=c/d;
    p=((p)%b+b)%b;
	printf("%lld",p);
	return 0;
}
