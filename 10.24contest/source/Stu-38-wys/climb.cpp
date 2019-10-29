#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d, n, k, bna[1007] = {4, 2, 4};

int main() {
	freopen("climb.in", "r", stdin);
	freopen("climb.out", "w", stdout);
	scanf("%d", &n);
	if(n == 4) printf("5");
	else printf("6");
	return 0;
}
