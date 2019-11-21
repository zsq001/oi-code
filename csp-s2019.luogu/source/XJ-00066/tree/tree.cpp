#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, T, a[2005];

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}
