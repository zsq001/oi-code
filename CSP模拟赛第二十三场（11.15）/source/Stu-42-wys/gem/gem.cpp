#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, a[1005], ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++) {
		int op, l, r, s, d;
		scanf("%d", &op);
		if(op == 1) {
			ans = 0;
			scanf("%d%d", &l, &r);
			int min = a[l], val = 0;
			for(int i = l + 1; i <= r; i++) {
				if(a[i] > min) {
					val += a[i] - min;
					min = a[i];
				}
				else {
					ans += val;
					val = 0;
					min = a[i];
				}
			}
			if(val) ans += val;
			printf("%d\n", val);
		}
		else {
			scanf("%d%d%d%d", &l, &r, &s, &d);
			for(int i = l; i <= r; i++) {
				a[i] += (s + d * (l - i));
			}
		}
	}
	return 0;
}
