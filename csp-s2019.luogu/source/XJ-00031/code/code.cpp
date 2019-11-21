#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

typedef long long ll;
const int MXB = 1 << 20;

struct IO {
	char buf[MXB], *p1, *p2;
	char pbuf[MXB], *pp;
	IO() : p1(buf), p2(buf), pp(pbuf) {
	}
	inline char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MXB, stdin);
		return p1 == p2 ? ' ' : *p1++;
	}
	template <typename T>
  inline T read() {
  	T x = 0;
  	bool sign = true;
  	char ch = gc();
  	while (!isdigit(ch)) {
  		if (ch == '-') sign = false;
  		ch = gc();
  	}
  	while (isdigit(ch)) {
  		x = x * 10 + ch - '0';
  		ch = gc();
  	}
  	return sign ? x : -x;
  }
	
	inline bool is_blank(char& ch) {
		return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
	}	
	
	inline void read(char* s) {
		char ch = gc();
		while (is_blank(ch)) ch = gc();
		while (!is_blank(ch)) {
			*s++ = ch;
			ch = gc();
		}
		*s = 0;
	}
	
	inline void read(char& ch) {
		ch = gc();
		while (is_blank(ch)) ch = gc();
	}
	
	inline void push(const char& ch) {
		if (pp - pbuf == MXB) {
			fwrite(pbuf, 1, MXB, stdout);
			pp = pbuf;
		}
		*pp++ = ch;
	}
	template <typename T>
	inline void write(T x) {
		static T st[35];
		int top = 0;
		do {
			st[top++] = x % 10;
			x /= 10;
		} while (x);
		while (top) push(st[--top] + '0');
	}
	template <typename T>
	inline void write(T x, char& ch) {
		write(x);
		push(ch);
	}
	
	inline void write(char* ch, int n, char last) {
		_rep(i, 0, n) {
			push(ch[i]);
		}
		push(last);
	}
	
	inline void open() {
		freopen("code.in", "r", stdin);
		freopen("code.out", "w", stdout);
	}
	
	inline void close() {
		fwrite(pbuf, 1, MXB, stdout);
		fclose(stdin);
		fclose(stdout);
	}
} io;

const ll MOD = LLONG_MAX; 
inline ll quick_pow(int a, int n) {
	ll ans = 1L, base = a;
	if (n >= 63) return MOD;
	while (n) {
		if (n & 1) ans *= base;
		base *= base;
		n >>= 1;
	}
	return ans; 
}

const int MXN = 65;
int n;
ll k;
char chs[MXN];
void gray_code(int flag) {
	int start = 0;
	bool sign = false;
	ll temp = quick_pow(2, flag - 1);
	while (temp) {
		//temp = flag == 64 ? LLONG_MAX : 
		if (k < temp) {
			chs[start++] = sign ? '1' : '0';
			sign = false;
		} else {
			chs[start++] = sign ? '0' : '1';
			sign = true;
			k -= temp;
		}
		temp >>=  1;
	}
	chs[start] = 0;
}

int main() {
	io.open();
	n = io.read<int>();
	k = io.read<ll>();
	//char chs[n + 1];
	if (n == 64) {
		if (k <= LLONG_MAX) gray_code(n); 
	} else {
		gray_code(n);
	}
	io.write(chs, n + 1, '\n');
	io.close();
	return 0;
}

