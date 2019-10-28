#include<bits/stdc++.h>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	if(n>=4)
	printf("%d",(n-2)%mod);
	if(n==3)
	printf("2");
	if(n==2)
	printf("1");
	if(n==1)
	printf("1");
	return 0;
}
