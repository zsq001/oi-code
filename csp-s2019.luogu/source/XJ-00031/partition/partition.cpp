#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <climits>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
typedef long long ll;
const int MXB = 1 << 20;
struct IO {
  char buf[MXB], *p1, *p2;
  IO() : p1(buf), p2(buf) {
  }	
  
  inline char gc() {
  	if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MXB, stdin);
  	return p1 == p2 ? ' ' : *p1++;
  }
  
  inline int read() {
  	int x = 0, sign = 1;
  	char ch = gc();
  	while (!isdigit(ch)) {
  	  if (ch == '-') sign = -1;
  	  ch = gc();
  	}
  	while (isdigit(ch)) {
  		x = (x << 3) + (x << 1) + ch - '0';
  		ch = gc();
  	}
  	return x * sign;
  }
  
  inline void open() {
  	freopen("partition.in", "r", stdin);
  	freopen("partition.out", "w", stdout);
  }
  
  inline void close() {
  	fclose(stdin);
  	fclose(stdout);
  }
} io;
const ll INF = LLONG_MAX;
const int MOD = 1 << 30;
int main() {
	io.open();
	int n = io.read();
	int type = io.read();
	int a[n];
	if (type == 1) {
		memset(a, 3242, sizeof(a));
	} else {
		_rep(i, 0, n) {
		  a[i] = io.read();
	  }	
	}
	ll dp[n + 1];
	ll prev[n + 1];
	_rep(i, 0, n + 1){
		dp[i] = INF;
	}
	dp[0] = 0;
	memset(prev, 0, sizeof(prev));
	for (int i = 1; i <= n; ++i) {
	  ll sum = 0;
		for (int k = 1; k <= i; ++k) {
	  	sum += a[i - k];
	  	//printf("i : %d, k : %d", i , k);
	  	ll total = sum * sum;
	  	//printf("%I64d, %I64d\n", sum, total);
	  	//printf("prev: %I64d\n", prev[i - k]);
	  	//printf("dp[%d] : %I64d\n", i, dp[i]);
	  	//printf("dp[%d] : %I64d\n", i - k, dp[i - k]);
	  	
	  	if (prev[i - k] <= sum && (dp[i] > (dp[i - k] + total))) {
			  dp[i] = dp[i - k] + total;
			  //printf("i : %d\n", i);
			  //printf("dp: %I64d\n", dp[i]);
			  //printf("sum: %I64d\n", sum);
				prev[i] = sum;	
	  	} 
	  }	
	}
	printf("%lld\n", dp[n]);
	io.close();
	return 0;
}
