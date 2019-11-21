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
  	freopen("meal.in", "r", stdin);
  	freopen("meal.out", "w", stdout);
  }
  
  inline void close() {
  	fclose(stdin);
  	fclose(stdout);
  }
} io;
const ll INF = LLONG_MAX;
const int MOD = 998244353;

int main() {
	io.open();
	int n = io.read();
	int m = io.read();
	int f[n][m];
	_rep(i, 0, n) {
		_rep(j, 0, m) {
			f[i][j] = io.read();
		}
	}
	int total = 0;
	_rep(i, 0, n) {
		_rep(j, 0, m) {
			if (f[i][j] == 0) continue;
			_rep(h, i + 1, n) {
				_rep(k, 0, m) {
				  if (j == k || f[h][k] == 0) {
					  continue;
				  }
				  total = (total + f[i][j] * f[h][k]) % MOD;
			  }
			}
		}
	}
	printf("%d\n", total);
	io.close();
	return 0;
}
