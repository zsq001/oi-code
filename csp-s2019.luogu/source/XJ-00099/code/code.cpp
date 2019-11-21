#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
ll n,k;
void solve(ll dep,ll x){
	if(dep==0) return ;
	ll t=pow((ll)2,dep-1);
	if(x>=t){
		printf("1");
		solve(dep-1,(t-x-1)+t);
	}
	else{
		printf("0");
		solve(dep-1,x);
	}
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	solve(n,k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
