#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ls p << 1
#define rs p << 1 | 1
const int MAXN = 1030;
using namespace std;
int n, m, x, y, xx, yy, num, ans, tag[MAXN][MAXN << 2], a[MAXN][MAXN << 2];
int read (){
	int xx = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		xx = (xx << 1) +(xx << 3) + (alpha ^48);
		alpha = getchar();
	}
	return sign ? -xx : xx;
}
struct Segment_Tree {
	void push_down(int p, int l, int r, int mid, int num) {
		tag[num][ls] ++;
		tag[num][rs] ++;
		a[num][ls] ++;
		a[num][rs] ++;
		tag[num][p] = 0;
	}
	void update(int p, int l, int r, int ql, int qr, int num) {
		if(ql <= l && qr >= r) {
			a[num][p] += r - l + 1;
			tag[num][p] ++;
			ans ++;
			return ;
		}
		int mid = (l + r) >> 1;
		if(tag[num][p])
			push_down(p, l, r, mid, num);
		if(ql <= mid)
			update(ls, l, mid, ql, qr, num);
		if(qr > mid)
			update(rs, mid + 1, r, ql, qr, num);
	}
	void query(int p, int l, int r, int num) {
		if(l == r) {
			printf("%d ", a[num][p]);
			return ;
		}
		int mid = (l + r) >> 1;
		if(tag[num][p])
			push_down(p, l, r, mid, num);
		query(ls, l, mid, num);
		query(rs, mid + 1, r, num);
	}
}Tree;
int main() {
	freopen("carpet.in", "r", stdin);
	freopen("carpet.out", "w", stdout);
	n = read();
	m = read();
	while(m--) {
		x = read();
		y = read();
		xx = read();
		yy = read();
		if(x > xx || y > yy) {
			swap(x, xx);
			swap(y, yy);
		}
		for(int j = x; j <= xx; j++) {
			ans = 0;
			Tree.update(1, 1, n, y, yy, j);
		}
	}
	for(int i = 1; i <= n; i++) {
		Tree.query(1, 1, n, i);
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
