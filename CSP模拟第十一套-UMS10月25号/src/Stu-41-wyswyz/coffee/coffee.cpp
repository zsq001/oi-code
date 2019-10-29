#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, h, b, e;
int cst[100007], ans[100007];

int main() {
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	while(~scanf("%d%d%d%d", &n, &h, &b, &e)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &cst[i]);
		}
//		init();
//		printf("OK\n");
		int mic = 99999, st = b - h + 1, now = -1;
		if(st < 1) st = 1;
		for(int i = b; i <= e; i++) {
			st = i - h + 1;
			if(st < 1) st = 1;
			if(now >= st) {
				if(mic >= cst[i]) now = i, mic = cst[i];
			}
			else {
				mic = 99999;
				for(int j = st; j <= i; j++) {
					if(cst[j] <= mic) {
						mic = cst[j];
						now = j;
					}
				}
			}
			ans[now]++;
		}
		for(int i = b; i <= e; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
		for(int i = b; i <= e; i++) ans[i] = 0;
	}
	return 0;
}
