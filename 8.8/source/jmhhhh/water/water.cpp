#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long 
#define mod 100000007

int inp[4000050];
int prime[5800000],cnt,n,ans=1;


int up(int a,int b){
	if(a%b!=0) return a/b +1;
	else return a/b;
}

ll ksc(int a,int b,int p){
	if(b==0) return 0;
	else if(b==1) return a%p;
	
	ll x=ksc(a,b/2,p);
	
	if(b%2==0) return (x+x)%p;
	else return ((x+x)%p+a)%p;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	inp[1]|= 1<<0;
	inp[1]|= 1<<1;
	for(int i=2;i<=n;i++){
		if( !( (inp[i/32+1]>>(i%32))&1) ){
			prime[++cnt]=i;
			int tp=1;
			for(int j=1;j<=n;j++){
	    		if(n/tp >= prime[cnt])
    			tp*=prime[cnt];
     			else break;
     		}
     		ans=ksc(ans,tp,mod);
		}
		for(int j=1;j<=cnt && up(n,prime[j]) >= i;j++){
			int next=prime[j]*i;
			inp[next/32+1]|= 1<<(next%32);
			if(i%prime[j]==0) break;
		}
	}
	printf("%d",ans);
	return 0;
}
