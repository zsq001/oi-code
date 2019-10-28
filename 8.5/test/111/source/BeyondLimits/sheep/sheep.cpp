#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 200050;
const int INF = 1 << 30;
using namespace std;
int n, m, opt, x, k, p, ans, a[MAXN], nextt[MAXN];
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
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	n = read();
	for(int i = 0; i < n; i++)
		nextt[i] = INF;
	for(int i = 0; i < n; i++) {
		a[i] = read();
		if(i + a[i] <= n - 1 && i + a[i] >= 0)
			nextt[i] = i + a[i];
	}
	m = read();
	for(int i = 1; i <= m; i++) {
		opt = read();
		if(opt == 1) {
			x = read();
			int p = x;	
			while(nextt[p] != INF) {
				++ans;
				p = nextt[p];
			}
			cout << ans + 1 << endl;
			ans = 0;
		}
		else {
			x = read();
			k = read();
			a[x] = k;
			for(int i = x; i < n; i++) {
				if(i + a[i] <= n - 1 && i + a[i] >= 0)
					nextt[i] = i + a[i];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
