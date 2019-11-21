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
	inline void write(T& x, char& ch) {
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
		freopen("brackets.in", "r", stdin);
		freopen("brackets.out", "w", stdout);
	}
	
	inline void close() {
		//fwrite(pbuf, 1, MXB, stdout);
		fclose(stdin);
		fclose(stdout);
	}
} io;

const int MXN = 5e5+10;
int n;
int fa[MXN];
int main() {
	
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	int n;
	scanf("%d", &n);
	// cout << n << endl;
	char chs[n + 1];
	scanf("%s", &chs);
	//printf("%s", chs);
	_rep(i, 0, n) {
	  scanf("%d", &fa[i + 1]); 
		// fa[i + 1] = io.read<int>();
	}
	// dp[i][j] = dp[i - 1][j] + dp[i][j -1] + dp[i - 1][j - 1] != 0 
	// if (str[i] == str[j]) dp[i - 1][j - 1] + 1
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n - 1; ++i) {
		dp[i][i + 1] = (chs[i] == '(' && chs[i + 1] == ')');
	}
	int res = 0; 
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len - 1 < n; ++i) {
			int j = i + len - 1;
			//if (i <= j) continue;
			//dp[i][j] = 0;
			dp[i][j] += dp[i + 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];	
			if (chs[i] == '(' && chs[j] == ')') {
			  if (j > 0 && dp[i + 1][j - 1] != 0) {
			    dp[i][j] += dp[i + 1][j - 1] + 1;
				}
			}
		}		
	}
	for(int i = 1; i < n; ++i) {
		res = res ^ ((i + 1) * dp[0][i]);
	}
	printf("%d\n", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

