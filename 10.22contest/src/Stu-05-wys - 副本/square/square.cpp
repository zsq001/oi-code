#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, num[200007], max1, max2, a[200007], b[200007];
int A, B, cnt;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		if(i % 2 == 1) {
			++max1;
			a[max1] = a[max1 - 1] + num[i];
		}
		else {
			++max2;
			b[max2] = b[max2 - 1] + num[i];
		}
	}
	int x, y;
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 0) {
			x = i / 2;
			y = i / 2;
			A = a[x] + b[max2] - b[y - 1];
			B = b[y] + a[max1] - a[x];
			if(A == B) cnt++;
		}
		else {
			x = i / 2;
			y = i / 2;
			A = a[x] + b[max2] - b[y];
			B = b[y] + a[max1] - a[x + 1];
			if(A == B) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
