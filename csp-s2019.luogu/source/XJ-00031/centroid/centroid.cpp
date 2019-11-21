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
  	freopen("centroid.in", "r", stdin);
  	freopen("centroid.out", "w", stdout);
  }
  
  inline void close() {
  	fclose(stdin);
  	fclose(stdout);
  }
} io;

inline int sum(int x) {
	return (1 + x) * x;
}
int main() {
	io.open();
	int sz = io.read();
	int cnt[sz];
	vector<int> u[sz];
	vector<int> v[sz];

	_rep(i, 0, sz) {
		cnt[i] = io.read();
		//printf("%d\n", cnt[i]);
		_rep(j, 0, cnt[i] - 1) {
			int u1 = io.read();
			int v1 = io.read(); 
			//printf("%d, %d\n", u1, v1);
		  u[i].push_back(u1);
		  v[i].push_back(v1);	
		}
	}
	_rep(i, 0, sz) {
		//printf("%d\n", cnt[i]);
		printf("%d\n", sum(cnt[i]));
	}
	io.close();
	return 0;
}
