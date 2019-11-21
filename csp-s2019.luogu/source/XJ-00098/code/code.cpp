#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar();}
	while(ch<='9'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

void work(ll l,ll r,ll k,ll num,bool op){
	if(num==0) exit(0);
	ll mid=(l+r)>>1;
	if(k<=mid&&op==0){
		printf("%c",'0');
		work(l,mid,k,num-1,0);
	}else if(k<=mid&&op){
		printf("%c",'1');
		work(l,mid,k,num-1,0);
	}else if(k>mid&&op){
		printf("%c",'0');
		work(mid+1,r,k,num-1,1);
	}else{
		printf("%c",'1');
		work(mid+1,r,k,num-1,1);
	}
}


int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	ll n,k;
	scanf("%lld",&n);
	if(n<=63){
		ll a=1ll<<n;
		scanf("%lld",&k);
		k++;
		work(1ll,a,k,n,0);
	}
	return 0;
}
