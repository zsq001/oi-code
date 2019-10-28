#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
const int MAXN = 10;
using namespace std;
struct node {
	int x, y;
}a[MAXN];
int n;
double r1, r2, z, x1, x2, x3;
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
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
	freopen("protect.in", "r", stdin);
	freopen("protect.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].y = read();
	}	
	sort(a + 1, a + n + 1, cmp);
	if(n == 3) {
		x1 = a[1].x;
		x2 = a[2].x;
		x3 = a[3].x;
		r1 = x2 - x1;
		r2 = x3 - 2 * x2 + x1;
		z = (r2 - r1) / (-3);
		printf("%.2lf\n", max(pow(x3 - x1, 2), 3 * pow(z, 2) + 2 * (r2 - r1) * z + pow(r1, 2) + pow(r2, 2)));
	}
	else printf("%.2lf\n", pow(a[n].x - a[1].x, 2));
	return 0;
}
