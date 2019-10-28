#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#define ls p << 1
#define rs p << 1 | 1
const int MAXN = 100050;
const int mod = 1e9 + 7;
typedef int intt;
#define int long long
using namespace std;
int n, q, opt, ql, qr, k, tag[MAXN << 2];
struct node {
	int num, fi;
}a[MAXN << 2];
struct mat {
	int m[20][20];
};
mat c, d, e;
mat mul(mat x, mat y) {
	mat z;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++)
			z.m[i][j] = 0;
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++) {
			for(int k = 1; k <= 2; k++) {
				z.m[i][j] = (z.m[i][j] % mod + (x.m[i][k] % mod) * (y.m[k][j] % mod)) % mod;
			}
		}
	}
	return z;
}
mat qpow(mat x, int y) {
	mat ans = c;
	while(y) {
		if(y & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}
int fib(int x) {
	if(x == 1 || x == 2)
		return 1;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++)
			c.m[i][j] = d.m[i][j] = e.m[i][j] = 0;
	}
	c.m[1][1] = c.m[2][2] = d.m[1][1] = d.m[1][2] = d.m[2][1] = 1;
	e = qpow(d, x - 2);
	return (e.m[1][1] + e.m[1][2]) % mod;
}
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
struct Segment_Tree {
	void push_up(int p) { a[p].fi = a[ls].fi % mod + a[rs].fi % mod; }
	/*void push_down(int p, int l, int r, int mid) {
		a[ls].num = (mid - l + 1) * tag[p];
		a[rs].num = (r - mid) * tag[p];
		a[ls].fi = fib(a[ls].num) % mod;
		a[rs].fi = fib(a[rs].num) % mod;
		//tag[ls] += tag[p];
		//tag[rs] += tag[p];
		tag[p] = 0;
	}*/
	void build(int p, int l, int r) {
		if(l == r) {
			a[p].num = read();	
			a[p].fi = fib(a[p].num) % mod;
			return ;
		}
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		push_up(p);
	}
	void update(int p, int l, int r, int ql, int qr, int k) {
		if(l == r) {
			a[p].num += k;
//			tag[p] += k;
			a[p].fi = fib(a[p].num) % mod;
			return ;
		}
		int mid = (l + r) >> 1;
		//if(tag[p])
		//	push_down(p, l, r, mid);
		if(ql <= mid)
			update(ls, l, mid, ql, qr, k);
		if(qr > mid)
			update(rs, mid + 1, r, ql, qr, k);
		push_up(p);
	}
	int query(int p, int l, int r, int ql, int qr) {
		if(ql <= l && qr >= r)
			return a[p].fi % mod;
		int mid = (l + r) >> 1, sum = 0;
		//if(tag[p])
		//	push_down(p, l, r, mid);
		if(ql <= mid)
			sum = (sum + query(ls, l, mid, ql, qr) % mod) % mod;
		if(qr > mid)
			sum = (sum + query(rs, mid + 1, r, ql, qr) % mod) % mod;
		push_up(p);
		return sum;
	}
}Tree;
intt main() {
	n = read();
	q = read();
	Tree.build(1, 1, n);
	while(q--) {
		opt = read();
		ql = read();
		qr = read();
		if(opt == 1) {
			k = read();
			Tree.update(1, 1, n, ql, qr, k);
		}
		else
			cout << Tree.query(1, 1, n, ql, qr) % mod << endl;
	}
	return 0;
}
