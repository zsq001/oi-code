#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
typedef double db;
const int MAXN = 100050;
using namespace std;
db ans;
int n, k, c, w, opt[MAXN], x[MAXN];
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
void dfs(int step, db p, db val) {
	if(step == n + 1) {
		ans = max(ans, val);
		return ;
	}
	if(opt[step] == 1) {
		dfs(step + 1, p * (1 - k * 0.01), val + 1.0 * x[step] * p);
		dfs(step + 1, p, val);
	}
	else {
		dfs(step + 1, p * (1 + c * 0.01), val - 1.0 * x[step] * p);
		dfs(step + 1, p, val);
	}
}
int main() {
	freopen("coal.in", "r", stdin);
	freopen("coal.out", "w", stdout);
	n = read();
	k = read();
	c = read();
	w = read();
	for(int i = 1; i <= n; i++) {
		opt[i] = read();
		x[i] = read();
	}
	dfs(1, w, 0);
	printf("%.2lf\n", ans);
	return 0;
}
/*
100 50 50 10
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
1 10
1 20
2 10
2 20
1 30
*/
