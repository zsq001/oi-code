#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 100050;
const int INF = 1 << 30;
using namespace std;
int n, m, x, y, h[MAXN], k[MAXN], f[MAXN];
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
void dp() {
	for(int i = 1; i <= n; i++) {
		if(h[i] == INF)
			continue;
		f[i] = 1;
		for(int j = 1; j < i; j++) {
			if(h[j] < h[i] && k[j] < k[i])
				f[i] = max(f[i], f[j] + 1);
		}
	}
}
void init() {
	memset(f, 0, sizeof(f));
}
int main() {
	freopen("building.in", "r", stdin);
	freopen("building.out", "w", stdout);
	n = read();
	m = read();
	x = read();
	y = read();
	for(int i = 1; i <= n; i++)
		h[i] = INF;
	h[x] = y;
	k[x] = y / x * 1.0;
	cout << "1" << endl;
	for(int i = 2; i <= m; i++) {
		init();
		x = read();
		y = read();
		h[x] = y;
		k[x] = y / x * 1.0;
		dp();
		cout << f[n] << endl;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
