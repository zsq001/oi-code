#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 350;
using namespace std;
int n, m, p1, p2, last, x[MAXN * MAXN], a[MAXN * MAXN];
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
int deal(int e, int ff) {
	int l = ff + 1, r = l + n - e - 1, bb = e;
	for(int i = l; i <= r; i++)
		x[++bb] = a[i] - x[e];
	return r;
}
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	n = read();
	m = (n * (n - 1)) >> 1;
	for(int i = 1; i <= m; i++)
		a[i] = read();
	sort(a + 1, a + m + 1);
	p1 = a[2] - a[1];
	p2 = a[n];
	x[3] = (p1 + p2) / 2;
	x[1] = a[2] - x[3];
	x[2] = a[1] - x[1];
	for(int i = 1; i <= n - 1; i++)
		last = deal(i, last);
	cout << "1" << endl;
	for(int i = 1; i <= n; i++)
		cout << x[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
