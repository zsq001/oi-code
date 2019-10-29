#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1000000007;

using namespace std;

int d, n, k, bna[1007] = {4, 2, 4};

int main() {
	freopen("banana.in", "r", stdin);
	freopen("banana.out", "w", stdout);
	scanf("%d", &d);
	while(d--) {
		printf("%d\n", bna[d]);
	}
	return 0;
}
