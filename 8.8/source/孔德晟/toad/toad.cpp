#include<stdio.h>
typedef long long ll;
ll ans;
void exgcd(ll a,ll b,ll &t,ll &k){
    if(b==0) t=1,k=0;
    else {
        exgcd(b,a%b,k,t);
        k-=a/b*t;
    }
}

int gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

int main(){
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
    ll x,y,m,n,l,i;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    int d=gcd(n-m,l);
    ll c=x-y;
    if(d<0) d=-d,c=-c;
    if(c%d){
        printf("Impossible");
        return 0;
    }
    ll t,k;
    exgcd(n-m,l,t,k);
    t *= c/d;
    l/=d;
    printf("%lld",((t%l)+l)%l);
    return 0;
}
