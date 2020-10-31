#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 50050;
using namespace std;
int n, m, v, p, q, vi[MAXN][5], pi[MAXN][5], f[MAXN];
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
int main() {
	freopen("budget.in", "r", stdin);
	freopen("budget.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= m; i++) {
		v = read();
		p = read();
		q = read();
		if(q == 0) {
			vi[i][0] = v;
			pi[i][0] = p;
		}
		else {
			if(!vi[q][1]) {
				vi[q][1] = v;
				pi[q][1] = p;
			}
			else {
				vi[q][2] = v;
				pi[q][2] = p;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = n; j >= 0; j--) {
			if(j >= vi[i][0])
				f[j] = max(f[j], f[j - vi[i][0]] + pi[i][0] * vi[i][0]);
			if(j >= vi[i][0] + vi[i][1])
				f[j] = max(f[j], f[j - vi[i][0] - vi[i][1]] + pi[i][0] * vi[i][0] + pi[i][1] * vi[i][1]);
			if(j >= vi[i][0] + vi[i][2])
				f[j] = max(f[j], f[j - vi[i][0] - vi[i][2]] + pi[i][0] * vi[i][0] + pi[i][2] * vi[i][2]);
			if(j >= vi[i][0] + vi[i][1] + vi[i][2])
				f[j] = max(f[j], f[j - vi[i][0] - vi[i][1] - vi[i][2]] + pi[i][0] * vi[i][0] + pi[i][1] * vi[i][1] + pi[i][2] * vi[i][2]);
		}
	}
	printf("%d\n", f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
