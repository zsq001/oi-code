#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ls p << 1
#define rs p << 1 | 1
typedef int intt;
#define int long long 
const int MAXN = 100050;
using namespace std;
struct node {
	int num, Max;
}a[MAXN << 2];
int n, m, opt, ql, qr;
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
	void push_up(int p) {
		a[p].num = a[ls].num + a[rs].num;
		a[p].Max = max(a[ls].Max, a[rs].Max);
	}
	void build(int p, int l, int r) {
		if(l == r) {
			a[p].num = a[p].Max = read();
			return ;
		}
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		push_up(p);
	}
	void update(int p, int l, int r, int ql, int qr) {
		if(l == r) {
			a[p].num = floor(sqrt(a[p].num));
			a[p].Max = floor(sqrt(a[p].Max));
			return ;
		}
		int mid = (l + r) >> 1;
		if(ql <= mid && a[ls].Max > 1)
			update(ls, l, mid, ql, qr);
		if(qr > mid && a[rs].Max > 1)
			update(rs, mid + 1, r, ql, qr);
		push_up(p);
	}
	int query(int p, int l, int r, int ql, int qr) {
		if(ql <= l && qr >= r) { return a[p].num; }
		int mid = (l + r) >> 1, sum = 0;
		if(ql <= mid)
			sum += query(ls, l, mid, ql, qr);
		if(qr > mid)
			sum += query(rs, mid + 1, r, ql, qr);
		return sum;
	}
}Tree;
intt main() {
	freopen("sculpture.in", "r", stdin);
	freopen("sculpture.out", "w", stdout);
	n = read();
	Tree.build(1, 1, n);
	m = read();
	while(m--) {
		opt = read();
		ql = read();
		qr = read();
		if(opt == 0)
			Tree.update(1, 1, n, ql, qr);
		else
			printf("%lld\n", Tree.query(1, 1, n, ql, qr));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
