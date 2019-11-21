#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef unsigned long long ll;

ll n,t[77];
ll k;

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%llu%llu",&n,&k);
	ll d=0ll;
	for(ll i=n;i;i--){
		t[i]=((k>>(i-1ll))&1ll)^d;
		d=((k>>(i-1ll))&1ll);
	}
	for(ll i=n;i;i--)printf("%llu",t[i]);puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
