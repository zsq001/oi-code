#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
const ll inf=1e9+7;
ll n;
ll num[1000010];
ll ta(ll m){
	if(m==1)
	return 2;
	if(m==2)
	return 5;
	else
	return (ta(m-1)*2+3)%inf;
}
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%lld",&n);	
	long long ans;
	long long head=1;
	head=(pow(2,n-1));
	head=head%inf;
	ans=ta(n)+head;
	ans=ans%inf;
	printf("%lld",ans);
	return 0;
}
