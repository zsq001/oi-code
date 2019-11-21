#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

//define
typedef unsigned long long ull;
const int maxn = 5e6 + 5;
int n, k;
ull a[maxn];
int bin[maxn], lgh;

inline void cal(unsigned long long fuck){
	while(fuck){
		bin[++lgh] = fuck%2;
		fuck = fuck >> 1;
	}
}

inline unsigned long long fstpow(int x){
	int res = 1;
	while(x--){
		res = res<<1;
	}
	return res;
}

//main
int main(){
	ios::sync_with_stdio(false);
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	cin >> n >> k;
	a[0] = 0; a[1] = 1;
	int flag = 1, last = 1;	
	for(register int i = 2; i <= k; ++i){
		a[i] = a[last] + fstpow(flag);
		last--;
		if(last == -1)last = i, flag++;
	}
	cal(a[k]);
	if(lgh < n){
		int m = n - lgh;
		while(m){
			cout << '0';m--;
		}
	}
	while(lgh){
		cout << bin[lgh--];
	}
	return 0;
}
