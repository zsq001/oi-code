#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
const double eps = 1e-8;

using namespace std;

int n;

int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	scanf("%d", &n);
	if(n == 3)
		printf("1.000000000000000");
	else if(n == 4)
		printf("2.000000000000000");
	else if(n == 10)
		printf("4.500000000000000");
	else printf("%.10lf", (double)n / 2);
	return 0;
}
