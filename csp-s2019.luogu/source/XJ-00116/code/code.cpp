#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ll long long
using namespace std;

ll n;
ll code[100000];
ll k;

void co(ll num,ll wei,ll l,ll r,ll d){
	ll mid = (l + r) / 2;
	if(l >= r){
		if(d == 1)
			code[wei] = 1;
		else
		 	code[wei] = 0;
		return ;
	}
	if(d == 1){
		num = r - num + l;
	}
	if(num > mid)
		co(num,wei + 1,mid + 1,r,1);
	else
		co(num,wei + 1,l,mid,0);
	if(d == 1)
		code[wei] = 1;
	else
		code[wei] = 0;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin >> n >> k;
	k += 1;
	ll ni = pow(2,n);
	co(k,0,1,ni,0);
	for(ll i = 1;i <= n;i++)
		cout << code[i];
	return 0;
}
